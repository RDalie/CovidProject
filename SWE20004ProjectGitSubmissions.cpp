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

	for ( ; ; )
	{
		cout<<"Which service would you like to access?"<<endl;
	    cout<<"\t 1- Check COVID-Test Recommendation"<<endl;
	    cout<<"\t 2- Update Covid test status and Location database updation"<<endl;
	    cout<<"\t 3- Display Updated High Risk Covid Location"<<endl;
        cout<<"\t 4- Update COVID Patient Details"<<endl;
    	cout<<"\t 5- Display the COVID Positive Patient Detail"<<endl;
    	cout<<"\t 6- Quit"<<endl;
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

			cout << "Enter your detail for COVID-Test Recommendation\n" << endl;

			// Patient ID
			cout << "Enter Patient Id:" << endl;
			getline(cin, pId);

			// Patient Name
			cout << "\nEnter Patient Name:" << endl;
			getline(cin, pName);

			// Patient DOB
			cout << "\nEnter Patient DOB (dd-mm-yyyy):" << endl;
			getline(cin, pDOB);

			// Patient Address
			cout << "\nEnter Patient Address:" << endl;
			getline(cin,pAddress);

			// Patient Location
			cout << "\nEnter Patient Visited Location:" << endl;
			getline(cin, pVisitedLocation);

			// Patient DateTime
			cout << "\nEnter Date and Time (dd-mm-yyyy):" << endl;
			getline(cin, pDateTime);

			// Patient Overseas Travel
			cout << "\nHave you travelled Overseas in the last few days?" << endl;
			getline(cin, pLastOverseasTravel);

			// Patient Test Result
			cout << "\nDo you have any previous Covid Test result (Positive/Negative):" << endl;
			getline(cin, pCovidTest);

			// Patient Alive or Dead
			cout << "\nIs the patient alive or dead?" << endl;
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
			cout<<"\n.................Updated High Risk Covid Locations....................\n"<<endl;
			string highRiskLocations;
			ifstream highRiskLoc("Locations.txt");
			if (highRiskLoc.is_open())
			{
				while (getline(highRiskLoc, highRiskLocations))
				{
					cout<<highRiskLocations<<'\n';
				}
			    highRiskLoc.close();
			}
			else
			{
				cout<<"Unable to open file";
			}
	        return 0;
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
	return 0;
}
