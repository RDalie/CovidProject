#include<iostream>
#include<string>
#include <fstream>
#include<iomanip>

using namespace std;
int main()
{
	int option;

	// Patient Variables
	string pId;
	string pName;
	string pDOB;
	string pAddress;
	string pVisitedLocation;
	string pDateTime;
	string pLastOverseasTravel;
	string pCovidTest;
	string pStatus;

	do
	{
		cout << "Which service would you like to access? \n 1- \n 2- \n 3- \n 4- \n 5- \n 6- \n" << endl;
		cout << "Please enter the desired service type: " << endl;

		cin >> option;
		cin.get();

		switch (option)
		{
		case 1:
		{
			//Enter your detail for COVID-Test Recommendation
			/*
			*/

			fstream patientDataFile;
			patientDataFile.open("Patients.txt", ios::app);

			cout << "Enter your detail for COVID-Test Recommendation\n\n" << endl;

			// Patient ID
			cout << "Enter Patient Id:\n" << endl;
			getline(cin, pId);

			// Patient Name
			cout << "Enter Patient Name:\n" << endl;
			getline(cin, pName);

			// Patient DOB
			cout << "Enter Patient DOB:\n" << endl;
			getline(cin, pDOB);

			// Patient Address
			cout << "Enter Patient Address:\n" << endl;
			getline(cin,pAddress);

			// Patient Location
			cout << "Enter Patient Visited Location:\n" << endl;
			getline(cin, pVisitedLocation);

			// Patient DateTime
			cout << "Enter Date and Time in the format (dd-mm-yyyy):\n" << endl;
			getline(cin, pDateTime);

			// Patient Overseas Travel
			cout << "Have you travelled Overseas in the last few days?\n" << endl;
			getline(cin, pLastOverseasTravel);

			// Patient Test Result
			cout << "Do you have a Covid Test result:\n" << endl;
			getline(cin, pCovidTest);

			// Patient Alive or Dead
			cout << "Is the patient alive or dead?\n" << endl;
			getline(cin, pStatus);

			patientDataFile << pId << "\t" << pName << "\t"
				<< pDOB << "\t" << pAddress << "\t" << pVisitedLocation
				<< "\t" << pDateTime << "\t" << pLastOverseasTravel << "\t"
				<< pCovidTest << "\t" << pStatus << endl;

			patientDataFile.close();

			break;
		}
		case 2:
		{
			// Submit Your Covid test status & Update the Location database
			/*
			*/
			cout << "Submit Your Covid test status & Update the Location database\n\n" << endl;
			break;
		}
		case 3:
		{
			// Display the Updated Location (High Risk for COVID) 
			/*
			*/
			cout << "Display the Updated Location (High Risk for COVID)\n\n" << endl;
			break;
		}
		case 4:
		{
			// Update COVID Patient Details
			/*
			*/
			cout << "Update COVID Patient Details\n\n" << endl;
			break;
		}
		case 5:
		{
			// Display the COVID Positive Patient Detail
			/*
			*/
			cout << "Display the COVID Positive Patient Detail\n\n" << endl;
			break;
		}
		default:
			break;
		}
	} while (option != 6);
	cout << "Thank you for using our service. \n Wear mask and keep practicing social distancing. \n Stay safe!!" << endl;
	return 0;
}


