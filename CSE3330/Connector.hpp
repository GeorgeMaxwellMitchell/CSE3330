#pragma once

namespace cse3330 {

    // Connector class
    // Holds all database connection behavior
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
        // Takes in query to send as a string
        //   and number of columns in the resulting table
        // Returns a two-dimensional vector of all tuples gathered
        std::vector< std::vector<std::string> > send_query(
            std::string& query,
            int no_of_columns);

        // Deleted constructors
        Connector(Connector const&) = delete;

    private:

        sql::Driver*        driver;         // Holds server info
        sql::Connection*    connection;     // Holds database info
        sql::Statement*     statement;      // Holds query to send
        sql::ResultSet*     result_set;     // Holds query response

    };

}