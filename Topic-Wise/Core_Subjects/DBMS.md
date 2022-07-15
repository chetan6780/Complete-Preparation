# Database Management System

<details>
    <summary><b>What is DBMS ? Mention advantages..</b></summary>
    <p>
        Database Management System (DBMS) is a software for storing and
        retrieving users&#8217; data while considering appropriate security
        measures. It consists of a group of programs which manipulate the
        database. The DBMS accepts the request for data from an application and
        instructs the operating system to provide the specific data. In large
        systems, a DBMS helps users and other third-party software to store and
        retrieve data.
    </p>
    <p><b>Advantages:</b></p>
    <ul>
        <li>Improved data sharing</li>
        <li>Improved data security</li>
        <li>Better data integration</li>
        <li>Minimised data inconsistency</li>
        <li>Improved data access</li>
        <li>Improved decision making</li>
        <li>Improved end-user productivity</li>
    </ul>
</details>
<details>
    <summary><b>What is Database?</b></summary>
    <p>
        A database is an organised collection of structured information, or
        data, typically stored electronically in a computer system. A database
        is usually controlled by a database management system (DBMS). Together,
        the data and the DBMS, along with the applications that are associated
        with them, are referred to as a database system, often shortened to just
        a database.
    </p>
</details>
<details>
    <summary><b>What is a database system?</b></summary>
</details>
<details>
    <summary><b>What is RDBMS ? Properties..</b></summary>
    <p>
        A Relational Database Management system (RDBMS) is a database management
        system that is based on the relational model. It has the following major
        components: Table, Record/Tuple/Row, Field, and Column/Attribute.
        Examples of the most popular RDBMS are MYSQL, Oracle, IBM DB2, and
        Microsoft SQL Server database.
    </p>
    <p>Relational databases have the following properties:</p>
    <ul>
        <li>Values are atomic.</li>
        <li>All of the values in a column have the same data type.</li>
        <li>Each row is unique.</li>
        <li>The sequence of columns is insignificant.</li>
        <li>The sequence of rows is insignificant.</li>
        <li>Each column has a unique name.</li>
        <li>
            Integrity constraints maintain data consistency across multiple
            tables.
        </li>
    </ul>
</details>
<details>
    <summary><b>Types of database languages</b></summary>
    <ul>
        <li>
            <b>Data Definition Language</b>: DDL stands for Data Definition
            Language. It is used to define database structure or pattern.
        </li>
        <li>
            <b>Data Manipulation Language</b>: DML stands for Data Manipulation
            Language. It is used for accessing and manipulating data in a
            database. It handles user requests.
        </li>
        <li>
            <b>Data Control Language</b>: DCL stands for Data Control Language.
            It is used to retrieve the stored or saved data.
        </li>
        <li>
            <b>Transaction Control Language</b>: TCL is used to run the changes
            made by the DML statement. TCL can be grouped into a logical
            transaction.
        </li>
    </ul>
</details>
<details>
    <summary><b>ACID properties (VVVVV IMP)</b></summary>
    <p>
        To ensure the consistency of the database, certain properties are
        followed by all the<br />transactions occurring in the system.
        <br />These properties are called ACID Properties of a transaction.
    </p>
    <ul>
        <li>Atomicity</li>
        <li>Consistency</li>
        <li>Isolation</li>
        <li>Durability</li>
    </ul>
</details>
<details>
    <summary><b>Difference between vertical and horizontal scaling</b></summary>
    <p>
        Scaling alters the size of a system. In the scaling process, we either
        compress or expand the system to meet the expected needs. The scaling
        operation can be achieved by adding resources to meet the smaller
        expectation in the current system, or by adding a new system in the
        existing one, or both.
    </p>
    <p>
        Vertical scaling keeps your existing infrastructure but adds computing
        power. Your existing pool of code does not need to change — you simply
        need to run the same code on machines with better specs. By scaling up,
        you increase the capacity of a single machine and increase its
        throughput. Vertical scaling allows data to live on a single node, and
        scaling spreads the load through CPU and RAM resources for your
        machines.
    </p>
    <p>
        Horizontal scaling simply adds more instances of machines without first
        implementing improvements to existing specifications. By scaling out,
        you share the processing power and load balancing across multiple
        machines.
    </p>
</details>
<details>
    <summary><b>What is sharding</b></summary>
    <p>
        Sharding is a method of splitting and storing a single logical dataset
        in multiple databases. By distributing the data among multiple machines,
        a cluster of database systems can store larger dataset and handle
        additional requests. Sharding is necessary if a dataset is too large to
        be stored in a single database. Moreover, many sharding strategies allow
        additional machines to be added. Sharding allows a database cluster to
        scale along with its data and traffic growth.
    </p>
</details>
<details>
    <summary><b>Keys in DBMS</b></summary>
    <p>
        A key is a set of attributes that can identify each tuple uniquely in
        the given relation.
    </p>
    <p>Types of Keys:</p>
    <ul>
        <li>
            <b>Super Key</b> &#8211; A superkey is a set of attributes that can
            identify each tuple uniquely in the given relation. A super key may
            consist of any number of attributes.
        </li>
        <li>
            <b>Candidate Key</b> &#8211; A set of minimal attribute(s) that can
            identify each tuple uniquely in the given relation is called a
            candidate key.
        </li>
        <li>
            <b>Primary Key</b> &#8211; A primary key is a candidate key that the
            database designer selects while designing the database. Primary Keys
            are unique and NOT NULL.
        </li>
        <li>
            <b>Alternate Key</b> &#8211; Candidate keys that are left
            unimplemented or unused after implementing the primary key are
            called alternate keys.
        </li>
        <li>
            <b>Foreign Key</b> &#8211; An attribute ‘X’ is called as a foreign
            key to some other attribute ‘Y’ when its values are dependent on the
            values of attribute ‘Y’. The relation in which attribute ‘Y’ is
            present is called the referenced relation. The relation in which
            attribute ‘X’ is present is called the referencing relation.
        </li>
        <li>
            <b>Composite Key</b> &#8211; A primary key composed of multiple
            attributes and not just a single attribute is called a composite
            key.
        </li>
        <li>
            <b>Unique Key</b> &#8211; It is unique for all the records of the
            table. Once assigned, its value cannot be changed i.e. it is
            non-updatable. It may have a NULL value.
        </li>
    </ul>
</details>
<details>
    <summary><b>Types of relationship</b></summary>
    <p>A relationship is defined as an association among several entities.</p>
    <ul>
        <li>
            Unary Relationship Set &#8211; Unary relationship set is a
            relationship set where only one entity set participates in a
            relationship set.
        </li>
        <li>
            Binary Relationship Set &#8211; Binary relationship set is a
            relationship set where two entity sets participate in a relationship
            set.
        </li>
        <li>
            Ternary Relationship Set &#8211; Ternary relationship set is a
            relationship set where three entity sets participate in a
            relationship set.
        </li>
        <li>
            N-ary Relationship Set &#8211; N-ary relationship set is a
            relationship set where ‘n’ entity sets participate in a relationship
            set.
        </li>
    </ul>
</details>
<details>
    <summary><b>Data abstraction in DBMS, three levels of it</b></summary>
    <p>
        Data Abstraction is a process of hiding unwanted or irrelevant details
        from the end user. It provides a different view and helps in achieving
        data independence which is used to enhance the security of data.
    </p>
    <p>
        Database systems include complex data-structures. In terms of retrieval
        of data, reduce complexity in terms of usability of users and in order
        to make the system efficient, developers use levels of abstraction that
        hide irrelevant details from the users. Levels of abstraction simplify
        database design.
    </p>
</details>
<details>
    <summary><b>Indexing in DBMS</b></summary>
    <p>
        Indexing is a way to optimise the performance of a database by
        minimising the number of disk accesses required when a query is
        processed. It is a data structure technique which is used to quickly
        locate and access the data in a database.
    </p>
</details>
<details>
    <summary><b>What is DDL (Data Definition Language)</b></summary>
    <p>
        DDL stands for Data Definition Language. It is used to define database
        structure or pattern.<br />It is used to create schema, tables, indexes,
        constraints, etc. in the database.<br />Using the DDL statements, you
        can create the skeleton of the database.<br />Data definition language
        is used to store the information of metadata like the number of tables
        and schemas, their names, indexes, columns in each table, constraints,
        etc.
    </p>
</details>
<details>
    <summary><b>What is DML (Data Manipulation Language)</b></summary>
    <p>
        DML stands for Data Manipulation Language. It is used for accessing and
        manipulating data in a database. It handles user requests.
    </p>
</details>
<details>
    <summary><b>What is normalization ? Types of normalization.</b></summary>
    <ul>
        <li>
            Normalization is the process of organizing data by disintegrating
            bigger table into smaller one’s<br />with proper dependencies
        </li>
        <li>
            Redundant Data wastes a lot of disk space and creates maintenance
            problems (Update, Insert and Delete Anomaly). Hence the DB tables
            should be Normalized.
        </li>
        <li>
            The process of Normalization is achieved by following some rules
            which are defined as Normal Forms
        </li>
        <li>
            There are basically 3 types of Normal Form – 1NF, 2NF, 3NF.
            Strictness increases as we go from 1NF to 3NF.
        </li>
        <li>
            Apart from the above mentioned Normal Form there exist one more Form
            called Boyce Codd Normal Form (BCNF) . This is an advanced version
            of 3NF and is even stricter than 3NF.
        </li>
    </ul>
    <p>
        <a
            href="https://takeuforward.org/dbms/normalization-in-dbms-what-is-normalization/"
            >Read normalisation in details</a
        >
    </p>
</details>
<details>
    <summary><b>What is denormalization ?</b></summary>
    <p>
        Denormalization is a database optimization technique in which we add
        redundant data to one or more tables. This can help us avoid costly
        joins in a relational database. Note that denormalization does not mean
        not doing normalisation. It is an optimization technique that is applied
        after doing normalisation.
    </p>
</details>
<details>
    <summary><b>What is functional dependency ?</b></summary>
    <p>
        A functional dependency is a constraint that specifies the relationship
        between two sets of attributes where one set can accurately determine
        the value of other sets. It is denoted as X → Y, where X is a set of
        attributes that is capable of determining the value of Y. The attribute
        set on the left side of the arrow, X is called Determinant, while on the
        right side, Y is called the Dependent.
    </p>
</details>
<details>
    <summary><b>E-R Model ?</b></summary>
    <p>
        ER model stands for an Entity-Relationship model. It is a high-level
        data model. This model is used to define the data elements and
        relationship for a specified system.
    </p>
    <p>
        It develops a conceptual design for the database. It also develops a
        very simple and easy to design view of data.<br />In ER modelling, the
        database structure is portrayed as a diagram called an
        entity-relationship diagram.
    </p>
</details>
<details>
    <summary><b>Conflict Serializability in DBMS ..</b></summary>
    <p>
        Serializability is a concept that helps us to check which schedules are
        serializable. A serializable schedule is the one that always leaves the
        database in consistent state.
    </p>
    <p>
        A schedule is called conflict serializability if after swapping of
        non-conflicting operations, it can transform into a serial schedule. The
        schedule will be a conflict serializable if it is conflict equivalent to
        a serial schedule.
    </p>
</details>
<details>
    <summary><b>What is CCP ? (Concurrency Control Protocols)</b></summary>
    <p>
        Concurrency Control is the management procedure that is required for
        controlling concurrent execution of the operations that take place on a
        database.
    </p>
    <p>
        The concurrency control protocols ensure the atomicity, consistency,
        isolation, durability and serializability of the concurrent execution of
        the database transactions.
    </p>
    <p>Therefore, these protocols are categorised as:</p>
    <ul>
        <li>Lock Based Concurrency Control Protocol</li>
        <li>Timestamp Concurrency Control Protocol</li>
        <li>Validation Based Concurrency Control Protocol</li>
    </ul>
</details>
<details>
    <summary><b>Entity, Entity Type, Entity Set, Weak Entity Set..</b></summary>
    <p>
        Entity in DBMS can be a real-world object with an existence, For
        example, in a College database, the entities can be Professor, Students,
        Courses, etc.
    </p>
    <p>
        The entity type is a collection of the entity having similar attributes.
    </p>
    <p>Types of Entity type:</p>
    <ul>
        <li>
            <b>Strong Entity Type</b>:Strong entities are those entity types
            which have a key attribute. The primary key helps in identifying
            each entity uniquely. It is represented by a rectangle.
        </li>
        <li>
            <b>Weak Entity Type</b>: Weak entity type doesn&#8217;t have a key
            attribute. Weak entity types can&#8217;t be identified on their own.
            It depends upon some other strong entity for its distinct identity.
        </li>
        <li>
            <b>Entity Set: </b>Entity Set is a collection of entities of the
            same entity type. We can say that entity type is a superset of the
            entity set as all the entities are included in the entity type.
        </li>
    </ul>
</details>
<details>
    <summary><b>What are SQL commands ? Types of them..</b></summary>
    <p>
        <a
            href="https://www.javatpoint.com/dbms-sql-command"
            target="_blank"
            rel="noopener"
            >https://www.javatpoint.com/dbms-sql-command</a
        >
    </p>
</details>
<details>
    <summary><b>Nested Queries in SQL ?</b></summary>
    <p>
        <a
            href="https://www.tutorialspoint.com/explain-about-nested-queries-in-dbms"
            target="_blank"
            rel="noopener"
            >https://www.tutorialspoint.com/explain-about-nested-queries-in-dbms</a
        >
    </p>
</details>
<details>
    <summary><b>What is JOIN .. Explain types of JOINs</b></summary>
    <p>
        <a
            href="https://www.javatpoint.com/dbms-sql-joins"
            target="_blank"
            rel="noopener"
            >https://www.javatpoint.com/dbms-sql-joins</a
        >
    </p>
</details>
<details>
    <summary><b>Inner and Outer Join</b></summary>
    <p>Here are the different types of the JOINs in SQL:</p>
    <ul>
        <li>
            <b>(INNER) JOIN: </b> Returns records that have matching values in
            both tables
        </li>
        <li>
            <b>LEFT (OUTER) JOIN: </b>Returns all records from the left table,
            and the matched records from the right table
        </li>
        <li>
            <b>RIGHT (OUTER) JOIN: </b>Returns all records from the right table,
            and the matched records from the left table
        </li>
        <li>
            <b>FULL (OUTER) JOIN:</b> Returns all records when there is a match
            in either left or right table
        </li>
    </ul>
</details>
<details>
    <summary><b>Diff between 2 tier and 3 tier architecture</b></summary>
    <p>
        <a
            href="https://www.geeksforgeeks.org/difference-between-two-tier-and-three-tier-database-architecture/"
            target="_blank"
            rel="noopener"
            >https://www.geeksforgeeks.org/difference-between-two-tier-and-three-tier-database-architecture/</a
        >
    </p>
</details>
<details>
    <summary><b>Diff between TRUNCATE and DELETE command ..</b></summary>
</details>
<details>
    <summary><b>Difference between Intension and Extension in a DataBase</b></summary>
</details>
<details>
    <summary><b>
        Difference between share lock and exclusive lock, definition of lock
    </b></summary>
</details>

<br>

> All rights reserved by [takeUforward!](https://takeuforward.org/interviews/must-do-questions-for-dbms-cn-os-interviews-sde-core-sheet/)
> Please find original Post [here](https://takeuforward.org/interviews/must-do-questions-for-dbms-cn-os-interviews-sde-core-sheet/).
