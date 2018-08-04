#include "stdafx.h"

#include "Connector.hpp"

#include "GUI.hpp"

// MySQL Connector C++ 1.1 Documentation at:
// https://dev.mysql.com/doc/connector-cpp/1.1/en/

namespace cse3330 {

    Connector::Connector() 
    :   driver{ nullptr },
        connection{ nullptr },
        statement{ nullptr },
        result_set{ nullptr } {

        // Need to initialize driver before making a connection
        driver = get_driver_instance();

    } // Connector

    Connector::~Connector() {

        // Must manually delete these members
        // Must be deleted in this order
        if (result_set != nullptr)
            delete result_set;

        if (statement != nullptr)
            delete statement;

        if (connection != nullptr)
            delete connection;

        // Do not need to delete driver

    } // ~Connector

    void Connector::connect_to_server(
        std::string& host_name,
        std::string& user_name,
        std::string& password,
        std::string& database) {

        // Connect to server, then connect to specific database
        // No reason to only connect to server for project
        std::cerr << "Connecting to server..." << std::endl;
        connection = driver->connect(host_name, user_name, password);
        
        std::cerr << "Connecting to database..." << std::endl;
        connection->setSchema(database);

        std::cerr << "Connected to " << database << " as " << user_name
            << " on " << host_name << std::endl;

    } // connect_to_server

    std::vector< std::vector<std::string> > Connector::send_query(
        std::string& query,
        int no_of_columns) {

        // Must establish a connection prior to sending queries
        assert(connection != nullptr);

        // Initialize statement from connection
        // Then execute statement and return result
        statement = connection->createStatement();
        result_set = statement->executeQuery(query);

        std::cerr << "Query executed: " << std::endl
            << query << std::endl;

        // Convert ResultSet to vector<vector<string>>
        std::vector< std::vector<std::string> > ret_set{};

        // Processes each row
        while (result_set->next()) {

            std::vector<std::string> row{  };

            // Adds each column to the row
            for (auto i = 1; i <= no_of_columns; i++) {

                row.push_back(result_set->getString(i) );

            }

            // Add row to return value
            ret_set.push_back(row);

        }

        return ret_set;

    } // send_query

} // namespace cse3330
