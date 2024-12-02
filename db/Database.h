#pragma once
#define HOST "localhost"
#define PORT "3306"
#define USER "madiba"
#define PASS "madiba"
#define DB "records"
#include <map>
#include <string>
#include "../utils.h"

namespace icpproject {
    using namespace std;
    using namespace MySql::Data::MySqlClient;
    using namespace System::Collections;
    using namespace System::Collections::Generic;
    using namespace System;
    using namespace System::Data;

    using ParamsH = Dictionary<STR, Object ^> ^ ;
    using Params = Dictionary<STR, Object ^>;

   public
    ref class Database {
       private:
        MySqlConnection ^ conn;
        MySqlCommand ^ cmd;
        MySqlDataReader ^ reader;
        MySqlDataAdapter ^ dta;
        MySqlTransaction ^ trans;
        Database() {
            conn = gcnew MySqlConnection(System::String::Format(
                "server={0};port={1};user={2};password={3};database={4}", HOST, PORT, USER, PASS, DB));
            cmd = gcnew MySqlCommand();
            dta = gcnew MySqlDataAdapter();

            try {
                conn->Open();
                cmd->Connection = conn;
            } catch (Exception ^ e) {
                throw gcnew Exception("Error Database Error: " + e->Message);
            }

            // Seed
            bool seed = false;

            if (seed) {
                try {
                    using namespace System::IO;
                    STR dbPath = "C:/Users/HP/Programming/C++/icp_project/db/db.sql";
                    StreamReader ^ sr = File::OpenText(dbPath);

                    STR contents = sr->ReadToEnd();
                    cmd->CommandText = contents;
                    cmd->ExecuteNonQuery();
                } catch (Exception ^ e) {
                    throw gcnew Exception("Failed to seed: " + e->Message);
                }
            }
        }

       public:
        ~Database() {
            if (reader != nullptr) reader->Close();
            conn->Close();
        }

        MySqlDataAdapter ^
            getDta() { return dta; }

            MySqlCommand
            ^
            getCmd() { return cmd; }

            MySqlDataReader
            ^
            execute(String ^ query) {
                cmd->CommandText = query;

                if (reader != nullptr) reader->Close();
                reader = cmd->ExecuteReader();
                return reader;
            }

            void beginTransaction() {
            trans = conn->BeginTransaction();
            cmd->Transaction = trans;
        }

        void rollback() {
            if (trans != nullptr) trans->Rollback();
            trans = nullptr;
        }

        void commit() {
            if (trans != nullptr) trans->Commit();
            trans = nullptr;
        }

        MySqlDataReader ^
            execute(String ^ query, ParamsH paramMap) {
                cmd->Parameters->Clear();
                cmd->CommandText = query;

                for each (STR key in paramMap->Keys) {
                    Object ^ val;
                    paramMap->TryGetValue(key, val);
                    cmd->Parameters->AddWithValue(key, val);
                }

                if (reader != nullptr) reader->Close();
                reader = cmd->ExecuteReader();
                cmd->Parameters->Clear();
                return reader;
            }

            int executeNoRet(String ^ query) {
            cmd->CommandText = query;

            if (reader != nullptr) reader->Close();
            return cmd->ExecuteNonQuery();
        }

        int executeNoRet(String ^ query, ParamsH paramMap) {
            cmd->Parameters->Clear();
            cmd->CommandText = query;

            for each (STR key in paramMap->Keys) {
                Object ^ val;
                paramMap->TryGetValue(key, val);
                cmd->Parameters->AddWithValue(key, val);
            }

            if (reader != nullptr) reader->Close();
            auto res = cmd->ExecuteNonQuery();
            cmd->Parameters->Clear();
            return res;
        }

        static Database ^ instance;
        static Database ^ Ins() {
            if (instance == nullptr) {
                instance = gcnew Database();
            }
            return instance;
        }
    };

}  // namespace icpproject

using db = icpproject::Database;

inline bool doesExist(STR query) {
    MySqlDataReader ^ reader = nullptr;
    try {
        reader = db::Ins()->execute(query);
        return reader->HasRows;
    } finally {
        if (reader != nullptr) {
            reader->Close();
        }
    }
}