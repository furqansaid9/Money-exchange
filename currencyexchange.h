#ifndef CURRENCY_EXCHANGE 
#define CURRENCY_EXCHANGE


#include <iostream>
#include <string>
#include <iomanip>
#include <stdlib.h>
#include <fstream>
#include<limits>


using namespace std;


const int NUMBER_OF_ROW= 8 ;

struct Table
{
    int RollNo ;  // 1,2 ,3 ,...,8

    string CurrencyName ; // US dollar ,thai baht ,...

    int unit ; // 1 ,100 ,1000 , how much 100 US dollar worth

    double We_Buy ;

    double We_sell ;

};



Table Agency1[NUMBER_OF_ROW]={

    {1," US DOLLAR ", 1 , 4.30   , 4.50 } ,

    {2," THAI BAHT ", 100 , 12.50  , 12.90 } ,

    {3," EURO ", 1 , 4.65   , 4.74} ,

    {4," JAPANESE YEN ", 1000 , 40.10  , 40.50} ,

    {5," SAUDI RIYAL ", 100 , 115.20 , 117.50} ,

    {6," BRITISH POUND ", 1 , 5.60   , 5.70} ,

    {7," QATAR RIYAL ", 100 , 118.90 , 121.10} ,

    {8," others ", 0 , 0 , 0} ,

    } ;



Table Agency2[NUMBER_OF_ROW]={

    {1," Brunei DOLLAR ", 1 , 3.12   , 3.15 } ,

    {2," Yemeni RIYAL ", 1000 , 16.57  , 16.80 } ,

    {3," Vietnamese DONG ", 100 , 0.016  , 0.021} ,

    {4," JAPANESE YEN ", 1000 , 41.20  , 41.50} ,

    {5," THAI BAHT ", 100 , 12.70  , 12.80 } ,

    {6," US DOLLAR ", 1 , 4.40   , 4.60 } ,

    {7," Chinese YUAN ", 100 , 63.4 , 64.10} ,

    {8," others ", 0 , 0 , 0} ,

    } ;





 Table Agency3[NUMBER_OF_ROW]={

    {1," Chinese YUAN ", 100 , 61.90 , 62.20} ,

    {2," Yemeni RIYAL ", 1000 , 15.10  , 15.50 } ,

    {3," Syrian pound ", 1000 , 8.07   , 8.15} ,

    {4," Canadian dollar", 1 , 3.8  , 4.20} ,

    {5," THAI BAHT ", 100 , 13.10  , 13.20 } ,

    {6," US DOLLAR ", 1 , 4.60  , 4.70 } ,

    {7," Brunei DOLLAR ", 1 , 3.5  , 3.12} ,

    {8," others ", 0 , 0 , 0} ,

    } ;




 string ColumnHeader[4] ={"CURRENCY","UNIT","WE BUY","WE SELL"} ;


//-------------------------------------------------------------

// global variables

 int TableChosen ;  // which agency

 int CurrencyUserChose , Sell_Or_Buy;

 double AmountOfMoney ;



//---------------------------------------------------------


void Display_ColumnHeader () ;  // display "CURRENCY","UNIT","WE BUY","WE SELL"

void Display_CurrencyName_Unit_WeSell_WeBuy  (Table [] ) ; // e.g.   1," Chinese YUAN ", 100 , 61.90 , 62.20  for the first row

void CheckWithinRange (int * , int  , int ) ;  // check if the value entered by the user is between 2 numbers

template <class AnyType >
void WrongDataType (istream & , AnyType *Value ); // in case the user entered wrong data type

//---------------------------------------------------------------

void CalculateFromToRinggit(Table [] ); // the user can only change from RM or To RM


//----------------------------------------------------------

void ChangeFromAnyCurrencyToAnyCurrency (  Table [] ) ;  // can deal with any currency except RM

double CalculateFromAndToAnyCurrency (int , int  , Table [] ) ; // how the calculation happened

//-----------------------------------------------------------------

void Hello ()  ;   //Function for displaying hello on the screen

void  TheBeginning () ; // a function that start the program

void Introduction ();  // small Introduction about the project

void  DisplayAgencies () ;  // choose which agency you want

void  ChoosingCurrency () ; // choose which Currency you want


//-----------------------------------------------------------------------


//receive an array that contain a sentence
//then display  character by character
void MovingText(char a[300])
{
    cout<<endl ;

    for(int i=0;a[i]!='\0' ; i++)
    {
        for (double j=0 ; j<9000000 ; j++) // just to delay
         ;
        cout<<a[i];

    }

}



//*******************************************************************************************



// a function that start the program
void  TheBeginning ()
{

	Hello ();  //Function for displaying hello on the screen

	Introduction () ; // small Introduction about the project

	string StartOver ;

	do{

    DisplayAgencies () ; // choose which agency you want

	ChoosingCurrency () ;  // choose which Currency you want

	//-------------------------------------------------------------------

	cin.ignore() ;

      cout<<"\n do you want to start over ?(y/n) \n" ;   //you can start from over again if you enter 'y'
      getline(cin , StartOver ) ;


      while ( !(StartOver=="y"||StartOver=="Y" ||StartOver=="N"|| StartOver=="n") )
      {
      	cout<<"\nEnter 'y' Or 'n' Only \n \n" ;
      	getline(cin, StartOver) ;

 	  }



	} while(StartOver=="y"||StartOver=="Y") ;



}


//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&

// display small Introduction about the project
void Introduction ()
{
	char text1[]="------------------------------------------------------------";  // array

    char text2[]= "~~~......Welcome To Money Exchange ......~~~"  ;

    char text3[]= "~~~......The Local Currency In This Program Is RM .....~~~"  ;

    char text4[]= "~~~......There Is 3 Agencies You can choose From  .....~~~"  ;

    char text5[]= "------------------------------------------------------------"  ;

    MovingText(text1);  // will make the sentence move
    MovingText(text2);
    MovingText(text3);
    MovingText(text4);
    MovingText(text5);


    cout << "\nEnter any key to Start The Program ";


    cin.get();


}

//ask the user to  choose which agency they want and then display the values in that agency
void DisplayAgencies ()
{

     string  ChangeAgency ;

   do{
   	  system("CLS");

    cout <<"1- AL AQSA Agency\n"
         <<"2- AL MADINA Agency\n"
         <<"3- AL ANSARI Agency\n\n";

    cout<<"choose which agency you want ?(1-3) \n";
     cin>>TableChosen ;

    if (cin.fail())    //call , in case wrong data type
      WrongDataType (cin , &TableChosen ) ;


     CheckWithinRange (&TableChosen ,1 , 3) ; // check if the input  between 1 and 3


     if (TableChosen==1)
        Display_CurrencyName_Unit_WeSell_WeBuy (Agency1); // call to display the first agency

     else if (TableChosen==2)
        Display_CurrencyName_Unit_WeSell_WeBuy (Agency2); // call to display the second agency

     else if (TableChosen==3)
        Display_CurrencyName_Unit_WeSell_WeBuy (Agency3); // call to display the third agency




      cin.ignore() ;

      cout<<"\n do you want to change agency ?(y/n) \n" ; // if the user don't like the exchange rate , he can change the agency
      getline(cin, ChangeAgency ) ;


      while ( !(ChangeAgency=="y"||ChangeAgency=="Y" ||ChangeAgency=="N"|| ChangeAgency=="n") )
      {
      	cout<<"Enter 'y' Or 'n' Only \n \n" ;
      	getline(cin, ChangeAgency ) ;

 	  }


    }while(ChangeAgency=="y"||ChangeAgency=="Y") ;

}

//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&77


// choose which Currency you want to deal with , only the currencies available in the agency you choose
 void ChoosingCurrency ()
 {
	cout<<"\nEnter The  Currnecy Number (1-8) \n";
    cin>>CurrencyUserChose ;

    if (cin.fail())   //call , in case wrong data type
      WrongDataType (cin , &CurrencyUserChose) ;


    CheckWithinRange (&CurrencyUserChose ,1 , 8) ;  // check if the input  between 1 and 8

    cout<<endl<<endl ;

	cout<<setprecision(2)<<fixed ;
//----------------------------------------------------------------------
	if (CurrencyUserChose==8) // if the user choose other , change from and to any currency except RM
    {
        if(TableChosen==1)

          ChangeFromAnyCurrencyToAnyCurrency (Agency1 ) ;   //call


        if(TableChosen==2)

          ChangeFromAnyCurrencyToAnyCurrency (Agency2 ) ;


        if(TableChosen==3)

          ChangeFromAnyCurrencyToAnyCurrency (Agency3 ) ;


      return ;

	}


//-----------------------------------------------------------------------

    //if the user decide to deal with RM
    cout<<"1-Buy : change from other currency to RM ( YOU PAY y CURRENCY , YOU GET x RM) \n\n"
	    <<"2-Sell : change from RM to other currency (YOU PAY y RM , YOU GET x CURRENCY)\n\n ";

    cout<<"Choose Buy Or Sell ? (1 - 2) \n";
    cin>> Sell_Or_Buy ;

    if (cin.fail())
      WrongDataType (cin , &Sell_Or_Buy ) ;

     CheckWithinRange (&Sell_Or_Buy ,1 , 2) ;


    cout<<endl<<endl ;


    cout<<"Enter The Amount Of Money You Want To Exchange\n";
    cin>>AmountOfMoney ;

    if (cin.fail())
      WrongDataType (cin, &AmountOfMoney ) ;


    cout<<endl<<endl ;

    if(TableChosen==1)
    CalculateFromToRinggit(Agency1) ;  //call


    if(TableChosen==2)
    CalculateFromToRinggit(Agency2) ;


    if(TableChosen==3)
    CalculateFromToRinggit(Agency3) ;

 }


//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&

// it will receive one of the agency
// and then display the values in that agency
 void Display_CurrencyName_Unit_WeSell_WeBuy  (Table store[])  //table is the structure name which became a datatype
 {
	                    //call to display column header  e.g. we sell   we buy
	Display_ColumnHeader ();

	                           // < 7 because 8th is just ' others '
   for (int IndexOfRow=0 ; IndexOfRow < NUMBER_OF_ROW-1 ; IndexOfRow++ )
   {
             // e.g.  1- US DOLLAR       1         4.3       4.5

   	  cout<<store[IndexOfRow].RollNo <<"-" <<setw(17) << left <<store[IndexOfRow].CurrencyName <<setw(10)<<left //dispaly currency names

   	  <<store[IndexOfRow].unit <<setw(10)<<left<<store[IndexOfRow].We_Buy <<setw(10)<<left<<store[IndexOfRow].We_sell<<endl;

                         // after displaying the 7th currency , the 8th is not currency , it's others
   	  if (IndexOfRow==6) // and it doesn't have any value for  ' we buy ' and ' we sell '
		{
                    // [7]
			cout<<store[IndexOfRow+1].RollNo <<"-"<<store[IndexOfRow+1].CurrencyName ; // to display 8- others only
			break;
        }

   }

     return ;
 }


//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&


 void Display_ColumnHeader () // to display column header  e.g. ' we sell '   ' we buy '
 {
 	cout<<setw(18)<<left ; //just for the first one

	for (int index =0 ; index < 4 ; index++)
	{
		cout<< ColumnHeader[index] ;

		cout<<setw(10)<<left ;
	}

    cout<<""; // without this the next line will get effect by setw


	cout<<endl ;

  	return ;

 }

//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&


// it will receive  the agency the user chose
// and use the global variable  AmountOfMoney to calculate from RM to other currency or from other currency to RM
void CalculateFromToRinggit( Table store[] )
 {

 	//---------------------------------------------------------------------------------------
	ofstream ToFile ;          // write to txt file

    ToFile.open("file.txt");

    ToFile<<"--------------------------------------------  "<<endl<<endl ;

	ToFile<<"Agency Chosen : " ;

	if(TableChosen==1)
		ToFile<<"AL AQSA Agency  \n\n"; // the name of the first agency


	if(TableChosen==2)
	    ToFile<<"AL MADINA Agency  \n\n";


	if(TableChosen==3)

	ToFile<<"AL ANSARI Agency  \n\n";
//-----------------------------------------------------------------------------------------------------


 	 double MoneyExchange ;


     if (Sell_Or_Buy==1)  // means the user chose buy , change from other Currency to RM
     {
         //the formula is (AmountOfMoney * we buy value)/ the unit value
                                             //      we buy value                   / unit
          MoneyExchange=  (AmountOfMoney  *  store[CurrencyUserChose -1].We_Buy) / store[CurrencyUserChose -1].unit ;

          cout<<" You Paid " <<AmountOfMoney << store[CurrencyUserChose -1].CurrencyName<<"---> you get "<< MoneyExchange << " RM" ;

    //------------------------------------------------------------------------------------------------------------------------------
	ToFile<<"Money Paid : " <<AmountOfMoney << store[CurrencyUserChose -1].CurrencyName<<endl<<endl ;   // write to txt file

	ToFile<<"Money Received : "<< MoneyExchange<<" RM"<<endl<<endl ;

	ToFile<<"--------------------------------------------  " ;

	//-------------------------------------------------------------------------------------------------------------------------------

	 }



      else if (Sell_Or_Buy==2) // means the user chose sell , from other currency to RM
      {
          //the formula is (AmountOfMoney * the unit value)/ the we sell value

     		MoneyExchange=  (AmountOfMoney * store[CurrencyUserChose -1].unit ) / store[CurrencyUserChose -1].We_sell ;

     		cout<<"You Paid "<<AmountOfMoney <<" RM --->  you get "<< MoneyExchange << store[CurrencyUserChose -1].CurrencyName ;

    //------------------------------------------------------------------------------------------------------------------------------
	ToFile<<"Money Paid : " <<AmountOfMoney << " RM"<<endl<<endl ; // write to txt file

	ToFile<<"Money Received : "<< MoneyExchange<< store[CurrencyUserChose -1].CurrencyName<<endl<<endl ;

	ToFile<<"--------------------------------------------  " ;

	//-------------------------------------------------------------------------------------------------------------------------------

	  }


         ToFile.close();

	  cout<<endl<<endl ;
 }

//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&

// it will receive  the agency the user chose
// and let the user choose from any currency  to any currency as long as that currency exist in that agency
// the user can't deal with RM in here
void ChangeFromAnyCurrencyToAnyCurrency ( Table store[])
{
//---------------------------------------------------------------------------------------
	ofstream ToFile ;    // write to txt file

    ToFile.open("file.txt");

    ToFile<<"--------------------------------------------  "<<endl<<endl ;

	ToFile<<"Agency Chosen : " ;

	if(TableChosen==1)
		ToFile<<"AL AQSA Agency  \n\n";


	if(TableChosen==2)
	    ToFile<<"AL MADINA Agency  \n\n";


	if(TableChosen==3)

	ToFile<<"AL ANSARI Agency  \n\n";
//-----------------------------------------------------------------------------------------------------

	int CurrencyFrom  , CurrencyTo  ;

	cout<<"from which currency you want to CHANGE FROM (1 - 7)\n" ; // can't choose 8 anymore
	cin>>CurrencyFrom ;

	if (cin.fail())
      WrongDataType (cin , &CurrencyFrom ) ;

    CheckWithinRange (&CurrencyFrom ,1 , 7) ;

	cout<<endl<<endl ;



	cout<<"To which currency you want to CHANGE TO (1 - 7) \n" ;
	cin>>CurrencyTo ;

	if (cin.fail())
      WrongDataType (cin , &CurrencyTo ) ; // call in case worng data type

     CheckWithinRange (&CurrencyTo ,1 , 7) ;


	while (CurrencyTo == CurrencyFrom ) //you can't change from us dollar to us dollar , it have to be different currency
    {
    	cout<<"Invalid number , You Can't Exchange To The Same Currency. choose another Currency \n" ;
    	cin>>CurrencyTo ;

    	if (cin.fail())
    	  WrongDataType (cin , &CurrencyTo ) ;
	}


	cout<<"Enter The Amount Of Money You Want To Exchange\n";
    cin>>AmountOfMoney ;

      if (cin.fail())
    	WrongDataType (cin , &AmountOfMoney ) ;  // call in case worng data type


	 cout<<"\nYou Paid "<<AmountOfMoney<<" "<< store[CurrencyFrom-1].CurrencyName <<" --->"<<" you  get "
	                          // call
	     << CalculateFromAndToAnyCurrency ( CurrencyFrom ,  CurrencyTo , store )<<" "<< store[CurrencyTo-1].CurrencyName ;

	//------------------------------------------------------------------------------------------------------------------------------
	ToFile<<"Money Paid : " <<AmountOfMoney<<" "<< store[CurrencyFrom-1].CurrencyName<<endl<<endl ; // write to txt file

	ToFile<<"Money Received : "<< CalculateFromAndToAnyCurrency ( CurrencyFrom ,  CurrencyTo , store )<<" "<< store[CurrencyTo-1].CurrencyName<<endl<<endl ;

	ToFile<<"--------------------------------------------  " ;


		 ToFile.close();
	//-------------------------------------------------------------------------------------------------------------------------------


	     cout<<endl<<endl ;

  }

//it will receive CurrencyFrom and CurrencyTo and  the agency the user chose and use the global variable  AmountOfMoney
//this function will calculate the change from any currency to any currency
double CalculateFromAndToAnyCurrency (int CurrencyFrom , int CurrencyTo , Table store[] )
{	// we going to change from any currency to RM
	// then from RM to Any currency

	double FromAnyCurrncyToRinggit ;

   // first  from any currency to RM  (AmountOfMoney * we buy value)/ the unit value

	   // RM    =                                           we buy values              / unit values
	FromAnyCurrncyToRinggit = (AmountOfMoney  *  store[CurrencyFrom -1].We_Buy) / store[CurrencyFrom -1].unit ;

	double FromRinggitToAnyCurrncy ;

	//then from RM to Any currency ( RM * the unit value)/ the we sell value


        // Any currency   =        RM                     *  unit                                  /  we sell value
	FromRinggitToAnyCurrncy =  (FromAnyCurrncyToRinggit * store[CurrencyTo -1].unit ) / store[CurrencyTo -1].We_sell ;

	return FromRinggitToAnyCurrncy ;
}

//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&

// it will receive the address of the variable , Smallest number , Bigest number
// this function will check if the input is between   Smallest number and Bigest number
 //and then ask to re enter if it's not between them
                          // pointer
void CheckWithinRange (int *ValueThatWeWillCheck , int SmallestValue , int BigestValue)
{
	while (*ValueThatWeWillCheck < SmallestValue || *ValueThatWeWillCheck > BigestValue)
    {
    	cout<<"Invalid number , Choose a number between "<<SmallestValue <<" and " << BigestValue<<endl;
    	cin>>*ValueThatWeWillCheck ;  //we use pointer because we want to change the original variable
                                      //if we don't use pointer , this function will not work
      if (cin.fail())
    	WrongDataType (cin , ValueThatWeWillCheck ) ;
	}
}

//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&7

//it will receive cin and the address of the variable we want to check
// this function will check if the input's data type is correct
// if it;s wrong , it will ask to re enter

template <class AnyType > // we use this because we will pass int and double
void WrongDataType (istream &cin , AnyType *Value )
{
	while (1)
	{


      if (cin.fail())
		{
			cin.clear();

			cin.ignore(numeric_limits<streamsize>::max(),'\n') ;

			cout << "WRONG DATA TYPE. Enter A Number" << endl;
		      cin>> *Value ;  //we use pointer because we want to change the original variable
                              //if we don't use pointer , this function will not work

		    if (!cin.fail())
		        break ;
		}


	}


}

//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&

void Hello ()    //Function for displaying hello on the screen
{
	int loader=0;

	printf("\n\n\n\n");
	printf("\t ||      || |||||||||| ||         ||           |||||||  \n");
	printf("\t ||      || ||         ||         ||          |||   ||| \n");
	printf("\t ||      || ||         ||         ||         ||||   ||||\n");
	printf("\t |||||||||| |||||||||| ||         ||         ||||   ||||\n");     //Strategically putting vertical bars into position to show "HELLO"
	printf("\t ||      || ||         ||         ||         ||||   ||||\n");
	printf("\t ||      || ||         ||         ||          |||   ||| \n");
	printf("\t ||      || |||||||||| |||||||||| ||||||||||   ||||||| \n");
	printf("\n\n");
	printf("\t\t\t\t LOADING ...\n\n");
	printf(" [\t\t\t\t\t\t\t\t\t]");
printf("\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");     //Going back to the bracket on the left
	printf("\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
	for (loader =0 ; loader <68 ; loader++)  //filling the loading bar..
	{

		for (double j=0 ; j<9000000 ; j++) // just to delay
		 ;
		printf("*");

	}
	printf("\n\n\n");
    system("CLS");
	return;
}

#endif