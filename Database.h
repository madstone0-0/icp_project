#pragma once
#define HOST "localhost"
#define PORT "3306"
#define USER "madiba"
#define PASS "madiba"
#define DB "records"
#include <format>
#include <map>

namespace icpproject {
    using namespace std;
    using namespace MySql::Data::MySqlClient;
    using namespace System::Collections;
    using namespace System::Collections::Generic;
    using namespace System;
    using namespace System::Data;

   public
    ref class Database {
       private:
        MySqlConnection ^ conn;
        MySqlCommand ^ cmd;
        MySqlDataReader ^ reader;
        MySqlDataAdapter ^ dta;
        Database() {
            conn = gcnew MySqlConnection(System::String::Format("server={0};port={1};user={2};password={3};database={4}",
                                                                HOST, PORT, USER, PASS, DB));
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

        MySqlDataReader ^
            execute(String ^ query) {
                cmd->CommandText = query;
                reader = cmd->ExecuteReader();
                return reader;
            }

        MySqlDataReader
            ^
            execute(String ^ query, Dictionary<String ^, String ^> ^ paramMap) {
                cmd->CommandText = query;

                for each (String^ key in paramMap->Keys) {
                    String^ value; 
                        paramMap->TryGetValue(key, value);
                    cmd->Parameters->AddWithValue(key, value);
                }

                reader = cmd->ExecuteReader();
                return reader;
            }


        int executeNoRet(String^ query) {
            cmd->CommandText = query;
            return cmd->ExecuteNonQuery();
        }

        int executeNoRet(String^ query, Dictionary<String^, String^>^ paramMap) {
            cmd->CommandText = query;

            for each (String ^ key in paramMap->Keys) {
                String ^ value;
                paramMap->TryGetValue(key, value);
                cmd->Parameters->AddWithValue(key, value);
            }

            return cmd->ExecuteNonQuery();
        }

            static Database
            ^ instance;
        static Database ^ Ins() {
            if (instance == nullptr) {
                instance = gcnew Database();
            }
            return instance;
        }

    };

}  // namespace icpproject

using db = icpproject::Database;