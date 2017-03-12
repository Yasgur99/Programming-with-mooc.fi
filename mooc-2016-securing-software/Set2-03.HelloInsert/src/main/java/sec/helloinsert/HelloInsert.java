package sec.helloinsert;

import java.io.FileReader;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.util.Scanner;
import org.h2.tools.RunScript;

public class HelloInsert {

    public static void main(String[] args) throws Exception {
        // Open connection to a database -- do not alter this code
        String databaseAddress = "jdbc:h2:file:./database";
        if(args.length > 0){
            databaseAddress = args[0];
        }

        Connection connection = DriverManager.getConnection(databaseAddress, "sa", "");

        try {
            // If database has not yet been created, insert content
            RunScript.execute(connection, new FileReader("sql/database-schema.sql"));
            RunScript.execute(connection, new FileReader("sql/database-import.sql"));
        } catch(Throwable t) {
            System.err.println(t.getMessage());
        }

        // Execute query and retrieve the query results
        ResultSet resultSet = connection.createStatement().executeQuery("SELECT * FROM Agent");

        // Do something with the results -- here, we print the books
        print(resultSet);

        addAgent(connection);

        resultSet = connection.createStatement().executeQuery("SELECT * FROM Agent");
        print(resultSet);

        connection.close();
    }

    public static void print(ResultSet resultSet) throws Exception {
        System.out.println("Agents in databse:");
        while(resultSet.next()) {
            String id = resultSet.getString("id");
            String name = resultSet.getString("name");

            System.out.println(id + "\t" + name);
        }
    }

    private static void addAgent(Connection connection) throws Exception {
        //Get info for new entry
        Scanner sc = new Scanner(System.in);
        System.out.println("\nAdd one:");
        System.out.print("What id? ");
        String id = sc.nextLine();
        System.out.print("What name? ");
        String name = sc.nextLine();
        System.out.println("");

        String query = "INSERT INTO Agent (id, name) VALUES (?, ?)";

        PreparedStatement pstmt = connection.prepareStatement(query);
        pstmt.setString(1, id);
        pstmt.setString(2, name);
        pstmt.execute();
    }
}
