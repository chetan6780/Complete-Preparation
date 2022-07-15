# Operating System

<details>
    <summary><b>
        What is the main purpose of an operating system? Discuss different
        types?
    </b></summary>
    <p>
        An operating system (OS) is system software that manages computer
        hardware, software resources, and provides common services for computer
        programs. So it manages the computer&#8217;s memory, processes, devices,
        files, and security aspects of the system. It also allows us to
        communicate with the computer without knowing how to speak the
        computer&#8217;s language. Without an operating system, a computer is
        not useful.
    </p>
    <p>Types of operating system:</p>
    <ul>
        <li>Batch OS</li>
        <li>Distributed OS</li>
        <li>Multitasking OS</li>
        <li>Network OS</li>
        <li>Real-Time OS</li>
        <li>Mobile OS</li>
    </ul>
    <p>
        Reference:
        <a
            href="https://www.geeksforgeeks.org/types-of-operating-systems/"
            target="_blank"
            rel="noopener"
            >https://www.geeksforgeeks.org/types-of-operating-systems/</a
        >
    </p>
</details>
<details>
    <summary><b>What is a socket, kernel and monolithic kernel ?</b></summary>
    <p>
        Socket:<br />A socket is defined as an endpoint for communication, A
        pair of processes communicating over a network employ a pair of sockets
        ,one for each process. A socket is identified by an IP address
        concatenated with a port number.<br />The server waits for incoming
        client requests by listening to a specified port. Once a request is
        received, the server accepts a connection from the client socket to
        complete the connection.
    </p>
    <p>
        Kernel is the central core component of an operating system that manages
        operations of computer and hardware. Kernel Establishes communication
        between user level application and hardware. Manages memory and CPU
        time. Decides state of incoming processes. Controls Disk, Memory, Task
        Management
    </p>
    <p>
        <b>Monolithic Kernel</b> (provides good performance but lots of lines of
        code)<br />It is one of the types of kernel where all operating system
        services operate in kernel space. It has dependencies between system
        components. It has huge lines of code which is complex.<br />Example :
        Unix, Linux, Open VMS, XTS-400 etc.
    </p>
</details>
<details>
    <summary><b>
        Difference between process and program and thread? Different types of
        process.
    </b></summary>
    <p>
        <b>Process:</b><br />Process is an instance of an executing program. For
        example, we write our computer programs in a text file and when we
        execute this program, it becomes a process which performs all the tasks
        mentioned in the program.
    </p>
    <p>
        <b>Program:</b><br />Program is a set of instructions to perform a
        certain task. Eg: chrome.exe, notepad.exe
    </p>
    <p>
        <b>Thread:</b><br />Thread is a path of execution within a process. A
        thread is also known as a lightweight process. The idea is to achieve
        parallelism by dividing a process into multiple threads. For
        example,Word processor uses multiple threads: one thread to format the
        text, another thread to process inputs.
    </p>
</details>
<details>
    <summary><b>Define virtual memory, thrashing, threads.</b></summary>
    <p>
        <b>Virtual Memory:</b><br />A computer can address more memory than the
        amount physically installed on the system. This extra memory is actually
        called virtual memory and it is a section of a hard disk that&#8217;s
        set up to emulate the computer&#8217;s RAM.<br />The main visible
        advantage of this scheme is that programs can be larger than physical
        memory. Virtual memory serves two purposes. First, it allows us to
        extend the use of physical memory by using a disk. Second, it allows us
        to have memory protection, because each virtual address is translated to
        a physical address.
    </p>
    <p>
        <b>Thrashing: </b><br />Thrashing is a condition or a situation when the
        system is spending a major portion of its time in servicing the page
        faults, but the actual processing done is very negligible. High degree
        of multiprogramming(if number of processes keeps on increasing in the
        memory), lack of frames (if a process is allocated too few frames, then
        there will be too many and too frequent page faults) causes Thrashing.
    </p>
    <p>
        <b>Threads:</b><br />A thread is a single sequential flow of execution
        of tasks of a process so it is also known as thread of execution or
        thread of control.
    </p>
</details>
<details>
    <summary><b>What is RAID ? Different types.</b></summary>
    <p>
        RAID, or “Redundant Arrays of Independent Disks” is a technique which
        makes use of a combination of multiple disks instead of using a single
        disk for increased performance, data redundancy or both.Data redundancy,
        although taking up extra space, adds to disk reliability. This means, in
        case of disk failure, if the same data is also backed up onto another
        disk, we can retrieve the data and go on with the operation.
    </p>
</details>
<details>
    <summary><b>
        What is a deadlock? Different conditions to achieve a deadlock.
    </b></summary>
    <p>
        A Deadlock is a situation where each of the computer processes waits for
        a resource which is being assigned to some other process. In this
        situation, none of the processes gets executed since the resource it
        needs is held by some other process which is also waiting for some other
        resource to be released.
    </p>
    <p>
        <b>How deadlock is achieved: </b>
        Deadlock happens when Mutual exclusion, hold and wait, No preemption and
        circular wait occurs simultaneously.
    </p>
    <p>Necessary Conditions for deadlock:</p>
    <ol>
        <li>Mutual Exclusion</li>
        <li>Hold and Wait</li>
        <li>No preemption</li>
        <li>Circular Wait</li>
    </ol>
</details>
<details>
    <summary><b>What is fragmentation? Types of fragmentation.</b></summary>
    <p>
        <b>Fragmentation:</b><br />An unwanted problem in the operating system
        in which the processes are loaded and unloaded from memory, and free
        memory space is fragmented. Processes can&#8217;t be assigned to memory
        blocks due to their small size, and the memory blocks stay unused. It is
        also necessary to understand that as programs are loaded and deleted
        from memory, they generate free space or a hole in the memory. These
        small blocks cannot be allotted to new arriving processes, resulting in
        inefficient memory use.
    </p>
    <p>
        The conditions of fragmentation depend on the memory allocation system.
        As the process is loaded and unloaded from memory, these areas are
        fragmented into small pieces of memory that cannot be allocated to
        incoming processes. It is called fragmentation.
    </p>
    <p>Types of fragmentation:<br />1. Internal<br />2. External</p>
</details>
<details>
    <summary><b>What is spooling ?</b></summary>
    <p>
        SPOOL is an acronym for simultaneous peripheral operations online.
        Spooling is a process in which data is temporarily held to be used and
        executed by a device, program, or system.<br />In spooling, there is no
        interaction between the I/O devices and the CPU. That means there is no
        need for the CPU to wait for the I/O operations to take place. Such
        operations take a long time to finish executing, so the CPU will not
        wait for them to finish.<br />The biggest example of Spooling is
        printing. The documents which are to be printed are stored in the SPOOL
        and then added to the queue for printing. During this time, many
        processes can perform their operations and use the CPU without waiting
        while the printer executes the printing process on the documents
        one-by-one.
    </p>
</details>
<details>
    <summary><b>
        What is semaphore and mutex (Differences might be asked)? Define Binary
        semaphore.
    </b></summary>
</details>
<details>
    <summary><b>Belady’s Anomaly</b></summary>
    <p>
        Bélády’s anomaly is the name given to the phenomenon where increasing
        the number of page frames results in an increase in the number of page
        faults for a given memory access pattern.
    </p>
    <p>
        <b>Solution to fix Belady’s Anomaly:</b><br />Implementing alternative
        page replacement algo helps eliminate Belady’s Anomaly.. Use of stack
        based algorithms, such as Optimal Page Replacement Algorithm and Least
        Recently Used (LRU) algorithm, can eliminate the issue of increased page
        faults as these algorithms assign priority to pages
    </p>
</details>
<details>
    <summary><b>Starving and Aging in OS</b></summary>
    <p>
        Starving/Starvation(also called Lived lock): Starvation is the problem
        that occurs when low priority processes get jammed for an unspecified
        time as the high priority processes keep executing. So starvation
        happens if a method is indefinitely delayed.
    </p>
    <p>
        Solution to Starvation : Ageing is a technique of gradually increasing
        the priority of processes that wait in the system for a long time.
    </p>
</details>
<details>
    <summary><b>Why does trashing occur?</b></summary>
    <p>
        High degree of multiprogramming(if number of processes keeps on
        increasing in the memory) , lack of frames(if a process is allocated too
        few frames, then there will be too many and too frequent page faults.)
        causes Thrashing.
    </p>
</details>
<details>
    <summary><b>What is paging and why do we need it?</b></summary>
    <p>
        Paging is a memory management scheme that eliminates the need for
        contiguous allocation of physical memory. This scheme permits the
        physical address space of a process to be non – contiguous.<br />Paging
        is used for faster access to data. When a program needs a page, it is
        available in the main memory(RAM) as the OS copies a certain number of
        pages from your storage device to main memory. Paging allows the
        physical address space of a process to be noncontiguous.
    </p>
</details>
<details>
    <summary><b>Demand Paging, Segmentation</b></summary>
    <p>
        Demand paging is a method of virtual memory management which is based on
        the principle that pages should only be brought into memory if the
        executing process demands them. This is often referred to as lazy
        evaluation as only those pages demanded by the process are swapped from
        secondary storage to main memory.<br />So demand paging works opposite
        to the principle of loading all pages immediately.
    </p>
    <p>
        Segmentation is a memory management technique in which the memory is
        divided into the variable size parts. Each part is known as a segment
        which can be allocated to a process.
    </p>
    <p>
        The details about each segment are stored in a table called a segment
        table. Segment table is stored in one (or many) of the segments.
    </p>
    <p>Segment table contains mainly two information about segment:</p>
    <p>
        Base: It is the base address of the segment<br />Limit: It is the length
        of the segment.
    </p>
</details>
<details>
    <summary><b>Real Time Operating System, types of RTOS.</b></summary>
    <p>
        A real-time operating system (RTOS) is a special-purpose operating
        system used in computers that has strict time constraints for any job to
        be performed and is intended to serve real time applications that
        possess data as it comes in , typically without buffer delays.
    </p>
    <p>Types of RTOS:</p>
    <ul>
        <li>Hard RTOS</li>
        <li>Firm RTOS</li>
        <li>Soft RTOS</li>
    </ul>
</details>
<details>
    <summary><b>Difference between main memory and secondary memory.</b></summary>
</details>
<details>
    <summary><b>Dynamic Binding</b></summary>
    <p>
        Static binding happens when the code is compiled, while dynamic bind
        happens when the code is executed at run time.
    </p>
    <p>
        <b>Static Binding:</b><br />When a compiler acknowledges all the
        information required to call a function or all the values of the
        variables during compile time, it is called “static binding”. As all the
        required information is known before runtime, it increases the program
        efficiency and it also enhances the speed of execution of a program.
        Static Binding makes a program very efficient, but it declines the
        program flexibility, as ‘values of variable’ and ‘function calling’ are
        predefined in the program. Static binding is implemented in a program at
        the time of coding. Overloading a function or an operator is the example
        of compile time polymorphism i.e. static binding.
    </p>
    <p>
        <b>Dynamic Binding</b> Calling a function or assigning a value to a
        variable, at run-time is called “Dynamic Binding”. Dynamic binding can
        be associated with run time ‘polymorphism’ and ‘inheritance’ in OOP.
        Dynamic binding makes the execution of a program flexible as it can
        decide what value should be assigned to the variable and which function
        should be called, at the time of program execution. But as this
        information is provided at run time it makes the execution slower as
        compared to static binding.
    </p>
</details>
<details>
    <summary><b>FCFS Scheduling</b></summary>
</details>
<details>
    <summary><b>SJF Scheduling</b></summary>
</details>
<details>
    <summary><b>SRTF Scheduling</b></summary>
    <p>
        SRTF Scheduling is a preemptive version of SJF scheduling. In SRTF, the
        execution of the process can be stopped after a certain amount of time.
        At the arrival of every process, the short term scheduler schedules the
        process with the least remaining burst time among the list of available
        processes and the running process.
    </p>
</details>
<details>
    <summary><b>LRTF Scheduling</b></summary>
    <p>
        This is a preemptive version of Longest Job First (LJF) scheduling
        algorithm. In this scheduling algorithm, we find the process with the
        maximum remaining time and then process it. We check for the maximum
        remaining time after some interval of time(say 1 unit each) to check if
        another process having more Burst Time arrived up to that time.
    </p>
</details>
<details>
    <summary><b>Priority Scheduling</b></summary>
    <p>
        Priority Scheduling is a method of scheduling processes that is based on
        priority. In this algorithm, the scheduler selects the tasks to work as
        per the priority.
    </p>
    <p>
        The processes with higher priority should be carried out first, whereas
        jobs with equal priorities are carried out on a round-robin or FCFS
        basis. Priority depends upon memory requirements, time requirements,
        etc.
    </p>
</details>
<details>
    <summary><b>Round Robin Scheduling</b></summary>
    <p>
        In Round-robin scheduling, each ready task runs turn by turn only in a
        cyclic queue for a limited time slice. This algorithm also offers
        starvation free execution of processes. Widely used preemptive
        scheduling method in traditional OS. All the jobs get a fair allocation
        of CPU. Cons include : Finding a correct time quantum is a quite
        difficult task in this system, Round-robin scheduling doesn’t give
        special priority to more important tasks.
    </p>
</details>
<details>
    <summary><b>Producer Consumer Problem</b></summary>
    <p>
        About Producer-Consumer problem: The Producer-Consumer problem is a
        classic problem that is used for multi-process synchronisation i.e.
        synchronisation between more than one processes.
    </p>
    <p>
        The job of the Producer is to generate the data, put it into the buffer,
        and again start generating data. While the job of the Consumer is to
        consume the data from the buffer.
    </p>
    <p>
        What&#8217;s the problem here?<br />The following are the problems that
        might occur in the Producer-Consumer:
    </p>
    <p>
        The producer should produce data only when the buffer is not full. If
        the buffer is full, then the producer shouldn&#8217;t be allowed to put
        any data into the buffer.<br />The consumer should consume data only
        when the buffer is not empty. If the buffer is empty, then the consumer
        shouldn&#8217;t be allowed to take any data from the buffer.<br />The
        producer and consumer should not access the buffer at the same time.
    </p>
    <p>We can solve this problem by using semaphores.</p>
</details>
<details>
    <summary><b>Banker’s Algorithm</b></summary>
    <p>
        It is a banker algorithm used to avoid deadlock and allocate resources
        safely to each process in the computer system. The &#8216;S-State&#8217;
        examines all possible tests or activities before deciding whether the
        allocation should be allowed to each process. It also helps the
        operating system to successfully share the resources between all the
        processes. The banker&#8217;s algorithm is named because it checks
        whether a person should be sanctioned a loan amount or not to help the
        bank system safely simulate allocation resources.
    </p>
</details>
<details>
    <summary><b>Explain Cache</b></summary>
    <p>
        Cache memory is an extremely fast memory type that acts as a buffer
        between RAM and the CPU. It holds frequently requested data and
        instructions so that they are immediately available to the CPU when
        needed.
    </p>
</details>
<details>
    <summary><b>Diff between direct mapping and associative mapping</b></summary>
</details>
<details>
    <summary><b>Diff between multitasking and multiprocessing</b></summary>
</details>

---

> All rights reserved by [takeUforward!](https://takeuforward.org/interviews/must-do-questions-for-dbms-cn-os-interviews-sde-core-sheet/)
> Please find original Post [here](https://takeuforward.org/interviews/must-do-questions-for-dbms-cn-os-interviews-sde-core-sheet/).
