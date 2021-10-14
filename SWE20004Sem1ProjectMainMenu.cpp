#include<iostream>

using namespace std;

int main()
{
	int option;
	do 
	{
	cout<<"Which service would you like to access? \n 1- \n 2- \n 3- \n 4- \n 5- \n 6- \n"<<endl;
	cout<<"Please enter the desired service type: "<<endl;
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
			// Submit Your Covid test status & Update the Location database
			/*
			*/
			cout<<"Submit Your Covid test status & Update the Location database\n\n"<<endl;
			break;
			}
		case 3:
			{
			// Display the Updated Location (High Risk for COVID) 
			/*
			*/
			cout<<"Display the Updated Location (High Risk for COVID)\n\n"<<endl;
			break;
			}	
		case 4:
			{
			// Update COVID Patient Details
			/*
			*/
			cout<<"Update COVID Patient Details\n\n"<<endl;
			break;
		    }
		case 5:
			{		
			// Display the COVID Positive Patient Detail
			/*
			*/
			cout<<"Display the COVID Positive Patient Detail\n\n"<<endl;
			break;
			}
		default:
			break;
	}
	}while (option != 6);
	cout<<"Thank you for using our service. \n Wear mask and keep practicing social distancing. \n Stay safe!!"<<endl;
	return 0;
}
