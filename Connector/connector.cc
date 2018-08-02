#include "connector.h"

// Disable warnings about dll-interface
#ifdef _MSC_VER
#pragma warning(disable : 4251)
#endif

#include "cppconn/driver.h"
#include "cppconn/statement.h"

#include <assert.h>

namespace cse3330 {

    Connector::Connector() 
    :   driver{ nullptr },
        connection{ nullptr },
        statement{ nullptr },
        result_set{ nullptr } {

        // Need to initialize driver before making a connection
        driver = get_driver_instance();

    }

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

    }

    void Connector::connect_to_server(
        std::string& host_name,
        std::string& user_name,
        std::string& password,
        std::string& database) {

        // Connect to server, then connect to specific database
        // No reason to only connect to server for project
        connection = driver->connect(host_name, user_name, password);
        connection->setSchema(database);

    }

    sql::ResultSet* Connector::send_query(std::string& query) {

        // Must establish a connection prior to sending queries
        assert(connection != nullptr);

        // Initialize statement from connection
        // Then execute statement and return result
        statement = connection->createStatement();
        result_set = statement->executeQuery(query);

        return result_set;

    }

} // namespace cse3330