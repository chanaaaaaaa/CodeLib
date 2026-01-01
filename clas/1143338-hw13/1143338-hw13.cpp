#include <iostream>
#include <iomanip>
#include <fstream>
#include <ctime>
#include <cstring>
using namespace std;

struct Date
{
   int year;
   int month;
   int day;
};

struct Reservation
{
   char flightNo[ 8 ]; // flight number
   char id[ 12 ];      // ID number
   char name[ 8 ];     // name
   char mobile[ 12 ];  // mobile phone number
   char date[ 12 ];    // departure date
   int tickets[ 8 ];
   // tickets[ 0 ]: not used
   // tickets[ 1 ]: number of full fare tickets
   // tickets[ 2 ]: number of child tickets
   // tickets[ 3 ]: number of infant tickets
   // tickets[ 4 ]: number of senior citizen tickets
   // tickets[ 5 ]: number of impaired tickets
   // tickets[ 6 ]: number of impaired companion tickets
   // tickets[ 7 ]: number of military tickets
};

struct Flight
{
   char flightNo[ 8 ];      // flight number
   char aircraft[ 8 ];      // aircraft model
   int departureAirport;    // departure airport code
   int arrivalAirport;      // arrival airport code
   char departureTime[ 8 ]; // departure time
   char arrivalTime[ 8 ];   // arrival time
   int dayWeek[ 7 ];        // the value of dayWeek[ i ] is 0 or 1
   // dayWeek[ 0 ] == 1 if and only if the flight flies on Sunday
   // dayWeek[ 1 ] == 1 if and only if the flight flies on Monday
   // dayWeek[ 2 ] == 1 if and only if the flight flies on Tuesday
   // dayWeek[ 3 ] == 1 if and only if the flight flies on Wednesday
   // dayWeek[ 4 ] == 1 if and only if the flight flies on Thursday
   // dayWeek[ 5 ] == 1 if and only if the flight flies on Friday
   // dayWeek[ 6 ] == 1 if and only if the flight flies on Saturday
};

struct FlightSeats
{
   char date[ 12 ];      // date
   char flightNo[ 8 ];   // flight number
   int departureAirport; // departure airport code
   int arrivalAirport;   // arrival airport code
   int availableSeats;   // the number of available seats
};

const char airportName[ 12 ][ 12 ] = { "", "Taipei",    "Taichung", "Chiayi",  "Tainan",
                                         "Kaohsiung", "Hualien", "Taitung",
                                         "Penghu",    "Kinmen",   "Beigan",  "Nangan" };

// row 0 and column 0 are not used,
// fullFare[ i ][ j ] is the full fare from airport i to airport j
const int fullFare[ 12 ][ 12 ] = {
   { 0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0 },
   { 0,    0,    0,    0,    0,    0, 1781, 2460, 2296, 2618, 2197, 2197 },
   { 0,    0,    0,    0,    0,    0,    0,    0, 1769, 2236,    0, 2686 },
   { 0,    0,    0,    0,    0,    0,    0,    0, 1721, 2217,    0,    0 },
   { 0,    0,    0,    0,    0,    0,    0,    0, 1697, 2231,    0,    0 },
   { 0,    0,    0,    0,    0,    0,    0,    0, 1876, 2393,    0,    0 },
   { 0, 1781,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0 },
   { 0, 2460,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0 },
   { 0, 2296, 1769, 1721, 1697, 1876,    0,    0,    0, 1768,    0,    0 },
   { 0, 2618, 2236, 2217, 2231, 2393,    0,    0, 1768,    0,    0,    0 },
   { 0, 2197,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0 },
   { 0, 2197, 2686,    0,    0,    0,    0,    0,    0,    0,    0,    0 } };

const int discount[ 8 ] = { 0, 100, 75, 0, 50, 50, 50, 95 };
// discount[ 0 ]: not used
// discount[ 1 ]: Full Fare Ticket (���B��)
// discount[ 2 ]: Child Ticket (�ൣ��):                 25% off of the full fare
// discount[ 3 ]: Infant Ticket (���಼):                Free of charge
// discount[ 4 ]: Senior Citizen Ticket (�q�Ѳ�):        50% off of the full fare
// discount[ 5 ]: Impaired Ticket (�R�߲�):              50% off of the full fare
// discount[ 6 ]: Impaired Companion Ticket (�R�߳��P��): 50% off of the full fare
// discount[ 7 ]: Military Ticket (�x�H��):               5% off of the full fare

const int maxNumReservations = 1000;

int enterChoice();

// perform booking
void booking();

// choose arrival airport by input its code, and assign the code to arrivalAirport
void chooseArrivalAirport( int departureAirport, int &arrivalAirport );

// input the departure date
void inputDepartureDate( char date[], int &departureDayWeek );

// return the number of days between currentDate and departureDate
int difference( Date departureDate, Date currentDate );

bool leapYear( int year );

// load all flights from Flight Schedule.dat and put them into the array flights
void loadFlightSchedules( Flight flights[], int &numFlights );

// load all flights from departureAirport to arrivalAirport,
// and put them into the array flights
void loadFlightSchedules( Flight flights[], int &numFlights,
     int departureAirport, int arrivalAirport, int departureDayWeek );

// load all flightSeats from departureAirport to arrivalAirport on departureDate,
// and put them into the array flightSeats
void loadFlightSeats( FlightSeats flightSeats[], int &numFlightSeats, char departureDate[],
                     int departureAirport, int arrivalAirport );

// display all flights from departureAirport to arrivalAirport
void displayFlights( const Flight flights[], int numFlights,
                    FlightSeats flightSeats[], int &numFlightSeats,
                    int departureAirport, int arrivalAirport, char date[] );

// choose a flight by input its number,
// and assign the number to reservation.flightNo
void chooseFlight( Reservation &reservation, const Flight flights[], int numFlights );

// input the number of tickets for each ticket type,
// and assign them to reservation.tickets
void inputNumTickets( Reservation &reservation, FlightSeats flightSeats[], int &numFlightSeats );

// during booking and refund application,
// the corresponding availableSeats in Flight Seats.dat should be modified
void modifyFlightSeatsFile( Reservation &reservation, int totalNumTickets );

void displayReservation( const Reservation reservation,
                        const Flight flights[], int numFlights );

// append reservation to the end of Reservations.dat
void saveReservation( const Reservation reservation );

// perform booking inquiry
bool bookingInquiry( const char id[] );

// perform refund application
void refundApplication();

// load all reservations from Reservations.dat and put them to the array reservations
void loadReservations( Reservation reservations[], int &numReservations );

int main()
{
   cout << "Welcome to UNI Air Domestic Flights Booking System\n";
   char id[ 12 ];
   int choice;

   while( ( choice = enterChoice() ) != 4 )
   {
      switch( choice )
      {
      case 1:
         booking(); // perform booking
         break;
      case 2:
         cout << "\nEnter ID number: ";
         cin >> id;
         bookingInquiry( id ); // perform booking inquiry
         break;
      case 3:
         refundApplication(); // perform refund application
         break;

      default:
         cout << "\nInput error!\n";
         break;
      }
   }

   cout << endl;
   system( "pause" );
}

int enterChoice()
{
   cout << "\nInput your choice:\n"
        << "1. Booking\n"
        << "2. Booking enquiry\n"
        << "3. Refund application\n"
        << "4. End\n? ";

   int menuChoice;
   cin >> menuChoice;
   return menuChoice;
}

// perform booking
void booking()
{
   // choose departure airport by input its code,
   // and assign the code to departureAirport
   int departureAirport;
   do {
      cout << "\nDeparture airport:\n";
      for( int i = 1; i <= 11; i++ )
         cout << setw( 2 ) << i << ". " << airportName[ i ] << endl;
      cout << "? ";

      cin >> departureAirport;
   } while( departureAirport < 1 || departureAirport > 11 );

   int arrivalAirport;
   // choose arrival airport by input its code, and assign the code to arrivalAirport
   chooseArrivalAirport( departureAirport, arrivalAirport );

   Reservation reservation = { "", "", "", "", "", 0, 0, 0, 0, 0, 0, 0, 0 };

   int departureDayWeek; // departureDayWeek == 0 if departure date is Sunday
                         // departureDayWeek == 1 if departure date is Monday
                         // departureDayWeek == 2 if departure date is Tuesday
                         // departureDayWeek == 3 if departure date is Wednesday
                         // departureDayWeek == 4 if departure date is Thursday
                         // departureDayWeek == 5 if departure date is Friday
                         // departureDayWeek == 6 if departure date is Saturday

   inputDepartureDate( reservation.date, departureDayWeek );

   Flight flights[ 20 ];
   int numFlights = 0;

   // load all flights from departureAirport to arrivalAirport,
   // and put them into the array flights
   loadFlightSchedules( flights, numFlights, departureAirport, arrivalAirport,
                        departureDayWeek );

   FlightSeats flightSeats[ 20 ];
   int numFlightSeats = 0;

   loadFlightSeats( flightSeats, numFlightSeats, reservation.date,
                    departureAirport, arrivalAirport );

   // display all flights from departureAirport to arrivalAirport
   displayFlights( flights, numFlights, flightSeats, numFlightSeats,
                   departureAirport, arrivalAirport, reservation.date );

   // choose a flight by input its number, and assign the number to reservation.flightNo
   chooseFlight( reservation, flights, numFlights );

   // input the number of tickets for each ticket type,
   // and assign them to reservation.tickets
   inputNumTickets( reservation, flightSeats, numFlightSeats );

   int totalNumTickets = 0;
   for( int i = 1; i < 8; i++ )
      totalNumTickets += reservation.tickets[ i ];

   if( totalNumTickets > 0 )
      modifyFlightSeatsFile( reservation, totalNumTickets );
   else
   {
      cout << "Your booking could not be completed!\n";
      return;
   }

   displayReservation( reservation, flights, numFlights );

   cout << "\nID number: ";
   cin >> reservation.id;
   cout << "\nName: ";
   cin >> reservation.name;
   cout << "\nMobile: ";
   cin >> reservation.mobile;

   // append reservation to the end of Reservations.dat
   saveReservation( reservation );

   cout << "\nBooking completed!\n";
}

// choose arrival airport by input its code, and assign the code to arrivalAirport
void chooseArrivalAirport( int departureAirport, int &arrivalAirport )
{
   do{
      cout << "\nArrival airport:\n";

      for( int i = 1; i <= 11; i++ )
         if( i != departureAirport && fullFare[ departureAirport ][ i ] > 0 )
            cout << setw( 2 ) << i << ". " << airportName[ i ] << endl;

      cout << "? ";
      cin >> arrivalAirport;

   }while( arrivalAirport < 1 || arrivalAirport > 11 ||
           arrivalAirport == departureAirport ||
           fullFare[ departureAirport ][ arrivalAirport ] == 0 );
}

void inputDepartureDate( char date[], int &departureDayWeek )
{
   // Use fixed base date: 2025-12-15 (Monday)
   int year = 2025;
   int month = 12;
   int day = 15;

   cout << "\nDeparture Date (Month):\n";

   int months[ 6 ][ 2 ];
   for( int i = 0; i < 6; i++ )
   {
      int m = month + i;
      months[ i ][ 0 ] = year + ( m - 1 ) / 12;
      months[ i ][ 1 ] = ( ( m - 1 ) % 12 ) + 1;

      cout << i + 1 << ". " << months[ i ][ 0 ] << "-" << months[ i ][ 1 ] << endl;
   }

   int choice;
   do{
      cout << "? ";
      cin >> choice;
   }while( choice < 1 || choice > 6 );

   int departureYear = months[ choice - 1 ][ 0 ];
   int departureMonth = months[ choice - 1 ][ 1 ];

   int daysOfMonth[ 13 ] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
   int endDay = daysOfMonth[ departureMonth ];
   if( departureMonth == 2 && leapYear( departureYear ) )
      endDay = 29;

   int startDay = 1;
   if( departureYear == year && departureMonth == month )
      startDay = day;

   int departureDay;
   do{
      cout << "\nDay (" << startDay << " ~ " << endDay << "): ";
      cin >> departureDay;
   }while( departureDay < startDay || departureDay > endDay );

   // format: yyyy/mm/dd
   date[ 0 ] = char( departureYear / 1000 % 10 + '0' );
   date[ 1 ] = char( departureYear / 100 % 10 + '0' );
   date[ 2 ] = char( departureYear / 10 % 10 + '0' );
   date[ 3 ] = char( departureYear % 10 + '0' );
   date[ 4 ] = '/';
   date[ 5 ] = char( departureMonth / 10 + '0' );
   date[ 6 ] = char( departureMonth % 10 + '0' );
   date[ 7 ] = '/';
   date[ 8 ] = char( departureDay / 10 + '0' );
   date[ 9 ] = char( departureDay % 10 + '0' );
   date[ 10 ] = '\0';

   Date departureDate = { departureYear, departureMonth, departureDay };
   Date currentDate = { year, month, day };
   int diff = difference( departureDate, currentDate );
   int currentDayWeek = 1; // 2025-12-15 is Monday (tm_wday = 1, where 0 is Sunday)
   departureDayWeek = ( currentDayWeek + diff ) % 7;
}

int difference( Date departureDate, Date currentDate )
{
   auto daysBeforeMonth = []( int year, int month )
   {
      int monthDays[ 13 ] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
      int days = 0;
      for( int m = 1; m < month; ++m )
      {
         days += monthDays[ m ];
         if( m == 2 && ( year % 400 == 0 || ( year % 4 == 0 && year % 100 != 0 ) ) )
            days += 1;
      }
      return days;
   };

   auto toDays = [&]( Date d )
   {
      int days = d.day + daysBeforeMonth( d.year, d.month );
      for( int y = 1; y < d.year; ++y )
         days += ( leapYear( y ) ? 366 : 365 );
      return days;
   };

   return toDays( departureDate ) - toDays( currentDate );
}

bool leapYear( int year )
{
   return ( year % 400 == 0 || ( year % 4 == 0 && year % 100 != 0 ) );
}

// load all flights from Flight Schedule.dat and put them into the array flights
void loadFlightSchedules( Flight flights[], int &numFlights )
{
   ifstream inFile( "Flight Schedule.dat", ios::in | ios::binary );

   if( !inFile )
   {
      numFlights = 0;
      return;
   }

   numFlights = 0;
   Flight flight;
   while( inFile.read( reinterpret_cast< char * >( &flight ), sizeof( Flight ) ) )
   {
      if( numFlights >= 19 )
         break;
      flights[ ++numFlights ] = flight;
   }

   inFile.close();
}

// load all flights from departureAirport to arrivalAirport,
// and put them into the array flights
void loadFlightSchedules( Flight flights[], int &numFlights,
     int departureAirport, int arrivalAirport, int departureDayWeek )
{
   ifstream inFile( "Flight Schedule.dat", ios::in | ios::binary );

   if( !inFile )
   {
      numFlights = 0;
      return;
   }

   numFlights = 0;
   Flight flight;
   while( inFile.read( reinterpret_cast< char * >( &flight ), sizeof( Flight ) ) )
   {
      if( flight.departureAirport == departureAirport &&
          flight.arrivalAirport == arrivalAirport &&
          flight.dayWeek[ departureDayWeek ] == 1 )
      {
         if( numFlights >= 19 )
            break;
         flights[ ++numFlights ] = flight;
      }
   }

   inFile.close();
}

void loadFlightSeats( FlightSeats flightSeats[], int &numFlightSeats, char departureDate[],
     int departureAirport, int arrivalAirport )
{
   ifstream inFile( "Flight Seats.dat", ios::in | ios::binary );

   if( !inFile )
   {
      numFlightSeats = 0;
      return;
   }

   // initialize all seats to 0 to avoid garbage when no matched record
   for( int i = 0; i < 20; ++i )
      flightSeats[ i ].availableSeats = 0;

   numFlightSeats = 0;
   FlightSeats seat;
   while( inFile.read( reinterpret_cast< char * >( &seat ), sizeof( FlightSeats ) ) )
   {
      if( strcmp( seat.date, departureDate ) == 0 &&
          seat.departureAirport == departureAirport &&
          seat.arrivalAirport == arrivalAirport )
      {
         if( numFlightSeats >= 19 )
            break;
         flightSeats[ ++numFlightSeats ] = seat;
      }
   }

   inFile.close();
}

// display all flights from departureAirport to arrivalAirport
void displayFlights( const Flight flights[], int numFlights,
                   FlightSeats flightSeats[], int &numFlightSeats,
                    int departureAirport, int arrivalAirport, char date[] )
{
   cout << airportName[ departureAirport ] << " to " << airportName[ arrivalAirport ]
        << " / Depart date: " << date << ".\n\n";
   cout << "Flight   Departure   Arrival   Fare   No. Available Seats\n";

   for( int i = 1; i <= numFlights; i++ )
   {
      // Find matching seat record by flight number
      int seatIndex = 0;
      for( int j = 1; j <= numFlightSeats; j++ )
         if( strcmp( flights[ i ].flightNo, flightSeats[ j ].flightNo ) == 0 )
         {
            seatIndex = j;
            break;
         }

      if( seatIndex > 0 && flightSeats[ seatIndex ].availableSeats > 0 )
         cout << setw( 6 ) << flights[ i ].flightNo
              << setw( 12 ) << flights[ i ].departureTime
              << setw( 10 ) << flights[ i ].arrivalTime
              << setw( 7 ) << fullFare[ departureAirport ][ arrivalAirport ]
              << setw( 22 ) << flightSeats[ seatIndex ].availableSeats << endl;
   }
}

// choose a flight by input its number, and assign the number to reservation.flightNo
void chooseFlight( Reservation &reservation, const Flight flights[], int numFlights )
{
   char flightNo[ 8 ];
   bool found = false;

   do{
      cout << "\nFlight number: ";
      cin >> flightNo;

      for( int i = 1; i <= numFlights; ++i )
         if( strcmp( flights[ i ].flightNo, flightNo ) == 0 )
         {
            found = true;
            strcpy_s( reservation.flightNo, sizeof( reservation.flightNo ), flightNo );
            break;
         }
   }while( !found );
}

// input the number of tickets for each ticket type, and assign them to reservation.tickets
void inputNumTickets( Reservation &reservation, FlightSeats flightSeats[], int &numFlightSeats )
{
   int i;
   for( i = 1; i <= numFlightSeats; i++ )
      if( strcmp( reservation.flightNo, flightSeats[ i ].flightNo ) == 0 )
         break;

   int numAvailableSeats = flightSeats[ i ].availableSeats;
   int maxNumTickets = ( numAvailableSeats < 4 ) ? numAvailableSeats : 4;

   do {
      cout << "\nNumber of infant tickets (0 ~ " << maxNumTickets << "): ";
      cin >> reservation.tickets[ 3 ];
   } while( reservation.tickets[ 3 ] < 0 || reservation.tickets[ 3 ] > maxNumTickets );

   int numTickets = 0;
   int numAdults = 0;
   do
   {
      numTickets = 0;

      cout << "\nNumber of full fare tickets (0 ~ " << maxNumTickets << "): ";
      cin >> reservation.tickets[ 1 ];
      numTickets += reservation.tickets[ 1 ];

      cout << "\nNumber of child tickets (0 ~ " << maxNumTickets << "): ";
      cin >> reservation.tickets[ 2 ];
      numTickets += reservation.tickets[ 2 ];

      cout << "\nNumber of senior citizen tickets (0 ~ " << maxNumTickets << "): ";
      cin >> reservation.tickets[ 4 ];
      numTickets += reservation.tickets[ 4 ];

      cout << "\nNumber of impaired tickets (0 ~ " << maxNumTickets << "): ";
      cin >> reservation.tickets[ 5 ];
      numTickets += reservation.tickets[ 5 ];

      cout << "\nNumber of impaired companion tickets (0 ~ " << maxNumTickets << "): ";
      cin >> reservation.tickets[ 6 ];
      numTickets += reservation.tickets[ 6 ];

      cout << "\nNumber of military tickets (0 ~ " << maxNumTickets << "): ";
      cin >> reservation.tickets[ 7 ];
      numTickets += reservation.tickets[ 7 ];

      numAdults = reservation.tickets[ 1 ] + reservation.tickets[ 4 ] +
                 reservation.tickets[ 5 ] + reservation.tickets[ 6 ] +
                 reservation.tickets[ 7 ];

      if( numTickets > maxNumTickets )
         cout << "\nYou can books a maximum of " << maxNumTickets
              << " passengers ( including children ).\n";
      else if( numAdults < reservation.tickets[ 3 ] )
         cout << "\nEach infant must always be accompanied by at least one adult.\n";
   } while( numTickets > maxNumTickets || numAdults < reservation.tickets[ 3 ] );

   cout << endl;
}

void modifyFlightSeatsFile( Reservation &reservation, int totalNumTickets )
{
   fstream inOutFile( "Flight Seats.dat", ios::in | ios::out | ios::binary );

   if( !inOutFile )
   {
      cerr << "File could not be opened." << endl;
      return;
   }

   FlightSeats seat;
   while( inOutFile.read( reinterpret_cast< char * >( &seat ), sizeof( FlightSeats ) ) )
   {
      if( strcmp( seat.date, reservation.date ) == 0 &&
          strcmp( seat.flightNo, reservation.flightNo ) == 0 )
      {
         seat.availableSeats -= totalNumTickets;
         if( seat.availableSeats < 0 )
            seat.availableSeats = 0;

         inOutFile.seekp( -static_cast< long >( sizeof( FlightSeats ) ), ios::cur );
         inOutFile.write( reinterpret_cast< char * >( &seat ), sizeof( FlightSeats ) );
         inOutFile.close();
         return;
      }
   }

   inOutFile.close();
}

void displayReservation( const Reservation reservation,
                         const Flight flights[], int numFlights )
{
   int k;
   for( k = 1; k <= numFlights; k++ )
      if( strcmp( reservation.flightNo, flights[ k ].flightNo ) == 0 )
         break;

   cout << "Ticket information:\n\n";
   cout << "Date: " << reservation.date << endl;
   cout << "Flight: B7-" << reservation.flightNo << endl << endl;

   int departureAirport = flights[ k ].departureAirport;
   int arrivalAirport = flights[ k ].arrivalAirport;

   cout << setw( 9 ) << right << airportName[ departureAirport ] << " -> "
        << setw( 9 ) << left << airportName[ arrivalAirport ] << endl;

   cout << setw( 9 ) << right << flights[ k ].departureTime << "    ";
   cout << setw( 9 ) << left << flights[ k ].arrivalTime << endl << endl;

   char ticketType[ 8 ][ 24 ] = { "", "Full Fare", "Child Fare", "Infant Fare",
                                      "Senior Citizen Fare",     "Impaired Fare",
                                      "Impaired Companion Fare", "Military Fare" };

   int total = 0;
   int fare;
   for( int i = 1; i <= 7; i++ )
      if( reservation.tickets[ i ] > 0 )
      {
         fare = fullFare[ departureAirport ][ arrivalAirport ] * discount[ i ] / 100;
         total += ( fare * reservation.tickets[ i ] );
         cout << right << setw( 23 ) << ticketType[ i ] << "  TWD "
              << setw( 4 ) << fare << " x " << reservation.tickets[ i ] << endl;
      }

   cout << "\nTotal: " << total << endl;
}

// append reservation to the end of Reservations.dat
void saveReservation( const Reservation reservation )
{
   // check duplicate
   Reservation reservations[ maxNumReservations ];
   int numReservations;
   loadReservations( reservations, numReservations );

   int totalNumTickets = 0;
   for( int i = 1; i <= 7; ++i )
      totalNumTickets += reservation.tickets[ i ];

   for( int i = 1; i <= numReservations; ++i )
      if( strcmp( reservations[ i ].flightNo, reservation.flightNo ) == 0 &&
          strcmp( reservations[ i ].id, reservation.id ) == 0 &&
          strcmp( reservations[ i ].date, reservation.date ) == 0 )
      {
         cout << "\nYou have already booked this flight on the same day.\n";
         // restore seats that had been deducted
         if( totalNumTickets > 0 )
         {
            Reservation temp = reservation;
            modifyFlightSeatsFile( temp, -totalNumTickets );
         }
         return;
      }

   ofstream outFile( "Reservations.dat", ios::out | ios::app | ios::binary );

   if( !outFile )
   {
      cerr << "File could not be opened." << endl;
      return;
   }

   outFile.write( reinterpret_cast< const char * >( &reservation ), sizeof( Reservation ) );
   outFile.close();
}

// perform booking inquiry
bool bookingInquiry( const char id[] )
{
   Reservation reservations[ maxNumReservations ];
   int numReservations = 0;
   loadReservations( reservations, numReservations );

   Flight flights[ 20 ];
   int numFlights = 0;
   loadFlightSchedules( flights, numFlights );

   bool found = false;
   int count = 0;

   for( int i = 1; i <= numReservations; ++i )
      if( strcmp( reservations[ i ].id, id ) == 0 )
      {
         if( !found )
            cout << "\n";
         found = true;

         bool flightFound = false;
         for( int j = 1; j <= numFlights; ++j )
            if( strcmp( flights[ j ].flightNo, reservations[ i ].flightNo ) == 0 )
            {
               flightFound = true;
               break;
            }

         if( !flightFound )
         {
            ifstream inFile( "Flight Schedule.dat", ios::in | ios::binary );
            if( inFile )
            {
               Flight tempFlight;
               while( inFile.read( reinterpret_cast< char * >( &tempFlight ), sizeof( Flight ) ) )
                  if( strcmp( tempFlight.flightNo, reservations[ i ].flightNo ) == 0 )
                  {
                     if( numFlights < 19 )
                        flights[ ++numFlights ] = tempFlight;
                     else
                        flights[ 19 ] = tempFlight;
                     flightFound = true;
                     break;
                  }
               inFile.close();
            }
         }

         if( flightFound )
         {
            cout << "\n" << ++count << ".  ";
            displayReservation( reservations[ i ], flights, numFlights );
         }
         else
            cerr << "\nError: Flight " << reservations[ i ].flightNo << " not found!\n";
      }

   if( !found )
   {
      cout << "\nNo reservations!\n";
      return false;
   }

   return true;
}

// perform refund application
void refundApplication()
{
   char id[ 12 ];

   cout << "\nEnter ID number: ";
   cin >> id;

   if( !bookingInquiry( id ) )
      return;

   int choice;
   cout << "\nEnter your choice: ";
   cin >> choice;

   Reservation reservations[ maxNumReservations ];
   int numReservations;
   loadReservations( reservations, numReservations );

   // Find matching reservations and their indices
   int matchingIndices[ maxNumReservations ];
   int count = 0;
   for( int i = 1; i <= numReservations; ++i )
      if( strcmp( reservations[ i ].id, id ) == 0 )
         matchingIndices[ ++count ] = i;

   // Validate choice
   if( choice < 1 || choice > count )
   {
      cout << "\nInvalid reservation number. Refund failed!\n";
      return;
   }

   // Get the reservation to be deleted
   int targetIndex = matchingIndices[ choice ];
   Reservation targetReservation = reservations[ targetIndex ];

   // Calculate total number of tickets
   int totalNumTickets = 0;
   for( int i = 1; i < 8; i++ )
      totalNumTickets += targetReservation.tickets[ i ];

   // Release seats by adding them back (pass negative value)
   if( totalNumTickets > 0 )
      modifyFlightSeatsFile( targetReservation, -totalNumTickets );

   // Delete the reservation record
   fstream inOutFile( "Reservations.dat", ios::in | ios::out | ios::binary );

   if( !inOutFile )
   {
      cerr << "File could not be opened." << endl;
      return;
   }

   Reservation emptyReservation = { "", "", "", "", "", 0, 0, 0, 0, 0, 0, 0, 0 };

   // Calculate file position (array index starts from 1, file position starts from 0)
   streampos pos = ( targetIndex - 1 ) * sizeof( Reservation );
   inOutFile.seekp( pos );
   inOutFile.write( reinterpret_cast< const char * >( &emptyReservation ), sizeof( Reservation ) );
   inOutFile.flush();
   inOutFile.close();

   cout << "\nThe seleted booking has been deleted.\n";
}

// load all reservations from Reservations.dat and put them to the array reservations
void loadReservations( Reservation reservations[], int &numReservations )
{
   ifstream inFile( "Reservations.dat", ios::in | ios::binary );

   if( !inFile )
   {
      numReservations = 0;
      return;
   }

   numReservations = 0;
   Reservation reservation;
   while( inFile.read( reinterpret_cast< char * >( &reservation ), sizeof( Reservation ) ) )
   {
      if( reservation.flightNo[ 0 ] == '\0' )
         continue;

      if( numReservations >= maxNumReservations - 1 )
         break;
      reservations[ ++numReservations ] = reservation;
   }

   inFile.close();
}
