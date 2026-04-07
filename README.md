# Concert Booking System (Low-Level Design)

A comprehensive Low-Level Design (LLD) implementation of a Concert Booking System in C++. This project demonstrates object-oriented design principles and various design patterns to manage concerts, user bookings, payments, and notifications.

## Features
- **Concert Management**: Add and maintain concert events, venues, seats, and timings in an in-memory database.
- **Search System**: Search and list available concerts filtered by artist, date, venue, or time.
- **Ticket Booking System**: Reserve exact matrix locations (row/col) for a concert and generate a dynamic ticket.
- **Payment Processing**: Simulated integrated payment gateway utilizing the **Adapter Pattern** with interfaces handling multiple payment APIs (`PhonePe`, `GPay`).
- **Notification Interface**: Dynamic notification triggers utilizing the **Strategy Pattern** with interchangeable modes of communication (`Email`, `SMS`).

## Core Architecture and Design Patterns

1. **Facade Pattern (Conceptual)**: `Concert_Booking_System` acts as the unified initializer and gateway context to orchestrate all the complex subsystems without tightly coupling the main function.
2. **Strategy Pattern**: The `Notification_Service` accepts any dynamic class fulfilling the `Notification_System` interface. Notification modes like `SMS` or `Email` can be injected interchangeably at runtime.
3. **Adapter Pattern**: The system processes payments using a standard `Payment_Service` interface. Since 3rd-party services (`PhonePe` and `GPay`) have different implementations, `PhonePeAdapter` and `GPayAdapter` adapt these concrete foreign classes into the standard interface.

## LLD Class Diagram

Below is the modular class dependency and architecture chart representing the Concert Booking System:

```mermaid
classDiagram
    class Concert_Booking_System {
        +Notification_Service* notification_service
        +Ticket_Booking_Service* ticket_booking_service
        +Search_Service* search_service
        +Concert_DB* concert_DB
    }
    
    class Concert_DB {
        +unordered_map registry
        +unordered_set st
        +insert_Concert(Concert* c)
        +remove_Concert(Concert* c)
    }

    class Concert {
        +int id
        +string artist
        +string venue
        +string date
        +string time
        +int seatfee
        +vector~vector~int~~ seat
        +fillSeat(positions)
    }

    class Search_Service {
        +Search_Concerts(type, cdb)
        +View_Available_Concerts(cdb)
    }

    class Ticket_Booking_Service {
        +book_ticket(user, cdb, positions, concert_id, amount)
        +get_ticket(user, cdb, concert_id, amount, positions)
    }

    class User {
        +int id
        +string name
        +string email
        +string ph_no
        +unordered_set~Ticket*~ booked_concerts
        +get_booked_concerts()
    }
    
    class Ticket {
        +string user_id
        +string concert_id
        +int amount
        +vector~pair~int,int~~ positions
        +get_details()
    }

    %% Payment Subsystem (Adapter Pattern)
    class Payment_Service {
        <<interface>>
        +pay(amount)*
    }
    class PhonePeAdapter {
        +pay(amount)
    }
    class GPayAdapter {
        +pay(amount)
    }
    class PhonePe {
        +pay_Phonepe(amount)
    }
    class GPay {
        +pay_GPay(amount)
    }

    %% Notification Subsystem (Strategy Pattern)
    class Notification_System {
        <<interface>>
        +notify(user, ticket)*
    }
    class SMS {
        +notify(user, ticket)
    }
    class Email {
        +notify(user, ticket)
    }
    class Notification_Service {
        +set_notification_service(Notification_System*)
        +notify(user, ticket)
    }

    %% Relationships
    Concert_Booking_System --> Concert_DB
    Concert_Booking_System --> Search_Service
    Concert_Booking_System --> Ticket_Booking_Service
    Concert_Booking_System --> Notification_Service
    
    Concert_DB *-- Concert
    Ticket_Booking_Service ..> Ticket : Creates
    User o-- Ticket : Books
    
    Notification_Service o-- Notification_System : Strategy Injection
    Notification_System <|-- SMS
    Notification_System <|-- Email
    
    Payment_Service <|-- PhonePeAdapter : Adapts
    Payment_Service <|-- GPayAdapter : Adapts
    PhonePeAdapter --> PhonePe : Wraps
    GPayAdapter --> GPay : Wraps
```

## How to Build & Run
Ensure you have a C++17 compatible compiler installed (like `g++`).

Run the following command to compile the system:
```bash
g++ -std=c++17 Concert_Booking_System.cpp -o main.exe
```

Run the compiled executable:
```bash
./main.exe
```

## File Structure breakdown
- `Concert_Booking_System.cpp`: Main subsystem context and execution gateway.
- `Concert_DB.cpp`: In-memory data structures holding active concert availability. 
- `Search_Service.cpp`: Performs availability scans and formatting.
- `Ticket_Booking_Service.cpp`: Manages concurrency constraints and validates user matrix seat selections.
- `Payment_Service.cpp`: Adapter implementations for third-party mock payment gateways.
- `Notification_Service.cpp`: Communication dispatch implementations (SMS, Email integrations).
- `User.cpp` / `Ticket.cpp` / `Concert.cpp`: Core application logic objects/models.
"# Concert_Booking_System_Low_Level_Design" 
