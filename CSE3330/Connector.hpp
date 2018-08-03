#pragma once

namespace cse3330 {

    // Connector class
    // Holds all database connection behavior
    // Links with the MySQL Connector C++ library dynamically
    class Connector final {

    public:

        Connector();
        ~Connector();

        // Connects client to server
        void connect_to_server(
            std::string& host_name,
            std::string& user_name,
            std::string& password,
            std::string& database);

        // Basic query sender
        sql::ResultSet* send_query(std::string& query);

    private:

        sql::Driver*        driver;         // Holds server info
        sql::Connection*    connection;     // Holds database info
        sql::Statement*     statement;      // Holds query to send
        sql::ResultSet*     result_set;     // Holds query response

    };

}