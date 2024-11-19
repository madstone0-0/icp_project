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
        }

       public:
        ~Database() {
            if (reader != nullptr) reader->Close();
            conn->Close();
        }

        MySqlCommand ^
            getCmd() { return cmd; }

            MySqlDataReader
            ^
            execute(String ^ query) {
                cmd->CommandText = query;
                reader = cmd->ExecuteReader();
                return reader;
            }

            MySqlDataReader
            ^
            execute(String ^ query, ParamsH paramMap) {
                cmd->CommandText = query;

                for each (STR key in paramMap->Keys) {
                    Object ^ val;
                    paramMap->TryGetValue(key, val);
                    cmd->Parameters->AddWithValue(key, val);
                }

                reader = cmd->ExecuteReader();
                cmd->Parameters->Clear();
                return reader;
            }

            int executeNoRet(String ^ query) {
            cmd->CommandText = query;
            return cmd->ExecuteNonQuery();
        }

        int executeNoRet(String ^ query, ParamsH paramMap) {
            cmd->CommandText = query;

            for each (STR key in paramMap->Keys) {
                Object ^ val;
                paramMap->TryGetValue(key, val);
                cmd->Parameters->AddWithValue(key, val);
            }

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