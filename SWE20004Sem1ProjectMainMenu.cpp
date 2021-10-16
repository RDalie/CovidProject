#include<iostream>

using namespace std;

int main()
{
	int option;
	for ( ; ; ) //Infinite loop 
	{
	cout<<"Which service would you like to access?"<<endl;
	cout<<"\t 1- Check COVID-Test Recommendation"<<endl;
	cout<<"\t 2- Update Covid test status and Location database updation"<<endl;
	cout<<"\t 3- Display Updated High Risk Covid Location"<<endl;
	cout<<"\t 4- Update COVID Patient Details"<<endl;
	cout<<"\t 5- Display the COVID Positive Patient Detail"<<endl;
	cout<<"\t 6- Quit"<<endl;
	cout<<"\nPlease enter the desired service type: "<<endl;
	cin>>option;
	switch (option)
	{
		case 1:
			{
				//Enter your detail for COVID-Test Recommendation
				/*
				*/
				cout<<"Enter your detail for COVID-Test Recommendation\n\n"<<endl;
				break;
			}
		case 2:
			{
				//Submit Your Covid test status & Update the Location database
				/*
				*/
				cout<<"Submit Your Covid test status & Update the Location database\n\n"<<endl;
				break;
			}
		case 3:
			{
				//Display the Updated Location (High Risk for COVID)
				/*
				*/
				cout<<"Display the Updated Location (High Risk for COVID)\n\n"<<endl;
				break;
			}
		case 4:
			{
				//Update COVID Patient Details
				/*
				*/
				cout<<"Update COVID Patient Details\n\n"<<endl;
				break;
			}
		case 5:
			{
				//Display the COVID Positive Patient Detail
				/*
				*/
				cout<<"Display the COVID Positive Patient Detail\n\n"<<endl;
				break;
			}
		case 6:
			{
				//Quit
				cout<<"Goodbye"<<endl;
				return 0; //Exiting the for loop
				break;
			}
		default:
			cout<<"Unknown selection, please try again\n\n"<<endl;
			break;
	}
	}
	cout<<"Thank you for using our service."<<endl;
	cout<<"Wear mask and keep practicing social distancing."<<endl;
	cout<<"Stay safe!!"<<endl;
	return 0;
}
