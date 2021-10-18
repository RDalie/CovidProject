#include<iostream>
#include<string>
#include <fstream>
#include<iomanip>


using namespace std;
int main()
{
	int option;



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

			// Select Symptoms : Display Symptoms In order of low, medium, high, open the file and read all the symptoms, ask the patient to select a symptom
			string filename = "Symptoms.txt";
			ifstream symptomsFile;
			string risk;
			string symptom;
			int numOfSymptoms;
			string low[6];
			string medium[6];
			string high[6];
			string userSymptom;
			string userRiskLevel = "none";

			symptomsFile.open(filename.c_str());

			cout << "Symptoms" << endl;
			for (int i = 0; i < 3; i++)
			{
				string num;

				getline(symptomsFile, risk);
				getline(symptomsFile, num);

				numOfSymptoms = std::stoi(num);

				cout << risk << endl;

				for (int j = 0; j < numOfSymptoms; j++)
				{
					getline(symptomsFile, symptom);
					cout << symptom << endl;;

					if (risk == "Low")
					{
						low[j] = symptom;
						
					}
					else if (risk == "Medium")
					{
						medium[j] = symptom;
						
					}
					else if (risk == "High")
					{
						high[j] = symptom;
						
					}
				}

				

				cout << "\n";

			}

			symptomsFile.close();



			cout << "Select Symptoms: (if none, type none)" << endl;
			getline(cin,userSymptom);
		
			if (userSymptom != "none")
			{
				for (string s : low)
				{

					if (s == userSymptom)
					{
						cout << "Your risk level is low" << endl;
						userRiskLevel = "low";
					}
				}

				for (string s : medium)
				{
					if (s == userSymptom)
					{
						cout << "Your risk level is medium" << endl;
						userRiskLevel = "medium";
					}
				}

				for (string s : high)
				{
					if (s == userSymptom)
					{
						cout << "Your risk level is high" << endl;
						userRiskLevel = "high";
					}
				}

			}
		 
			// Select Visited Location : Check if the visited Location is a high risk location, loop through the high risk location file and compare
			ifstream locationsFile;
			string location;
			bool visitedHighRiskLocation = false;
			locationsFile.open("Locations.txt");
			
			cout << "Enter the location visited: ";
			getline(cin, pVisitedLocation);
			cout << "\n";

			while (!locationsFile.fail())
			{
				getline(locationsFile, location);
				if (pVisitedLocation == location)
				{
					visitedHighRiskLocation = true;
					cout << "You have visited a high risk location" << endl;
					break;
				}

			}



			// Recommending Covid Test to the Patient who visited High Risk Location  and has any symptoms from (low, medium, high)
			if (visitedHighRiskLocation && ((userRiskLevel == "low") || userRiskLevel == "medium" || userRiskLevel == "high"))
			{
				cout << "You should go for a Covid Test because you visited a high risk location and have symptoms." << endl;
			}
			// Recommending Isolation if Patient did not Visit a high risk location but has a symptom from (low, medium)
			else if (!visitedHighRiskLocation && ((userRiskLevel == "low") || (userRiskLevel == "medium")))
			{
				cout << "You should isolate yourself because you have symptoms but you did not visit a high risk location." << endl;
			}
			// Recommending Covid Test if Patient did not visit a high risk Location but has high risk symptoms
			else if (!visitedHighRiskLocation && ((userRiskLevel == "high")))
			{
				cout << "You should go for a Covid Test because you have high risk symptoms but you did not visit a high risk location." << endl;
			}
			// Recommending No Test if Patient did not visit a high risk Location and has no Symptoms
			else if (!visitedHighRiskLocation && (userRiskLevel == "none"))
			{
				cout << "You don't need to go for a test because you did not visit a high risk location and have no symptoms." << endl;
			}
			// Recommending Isolation if the Patient visited a High Risk Location but has no symptoms
			else if (visitedHighRiskLocation && (userRiskLevel == "none"))
			{
				cout << "You should isolate yourself because you visited a high risk location but have no symptoms" << endl;
			}


			cout << "\n\n\n";
			break;
		}
		case 2:
		{

			cout << "Submit Your Covid test status & Update the Location database\n\n" << endl;

			// Submit Your Covid test status & Update the Location database
			/*
			*/
			string userId;
			string userTest;
			string userStatus;

			// Take ID and test status of patient, if positive, update in patient database,
			// ask for visited location, update location database

			// Step 1: Ask user for test Id and test status of patient
			cout << "Please enter your test Id: " << endl;
			getline(cin, userId);

			cout << "Please enter test status: " << endl;
			getline(cin, userTest);

			cout << "Is the patient alive or dead?" << endl;
			getline(cin, userStatus);

			// Step 2: Update in Patient Database
			//		// open two files one for reading and one for writing
			fstream patientsFile;
			fstream tempFile;

			patientsFile.open("PatientTest.txt");
			tempFile.open("temp.txt");

			string fileId;
			string fileTest;
			string fileStatus;

			patientsFile >> fileId >> fileTest >> fileStatus;
			do 
			{			
				cout << fileId << "\t" << fileTest << "\t" << fileStatus << endl;

				if ((userTest == "Positive") && (fileId == userId))
				{
					tempFile << fileId << "\t" << userTest << "\t" << userStatus << endl;
					
				}
				else
				{
					tempFile << fileId << "\t" << fileTest << "\t" << fileStatus << endl;
				}

				patientsFile >> fileId >> fileTest >> fileStatus;

			} while (!patientsFile.fail());

			tempFile.close();
			patientsFile.close();

		

			patientsFile.open("PatientTest.txt");
			tempFile.open("temp.txt");

			tempFile >> fileId >> fileTest >> fileStatus;
			do 
			{
				patientsFile << fileId << "\t" << fileTest << "\t" << fileStatus << endl;
				tempFile >> fileId >> fileTest >> fileStatus;

			} while (!tempFile.fail());

			patientsFile.close();
			tempFile.close();

			


			//		// read Patients and store in temp ( with update )
			//		// read from temp and store in Patients
			//		// Ask for visited location if Patient status positive
			// 
			string locationVisited;
			if (userTest == "Positive")
			{
				cout << "Please enter the name of the location visited: " << endl;
				getline(cin, locationVisited);
			}

			fstream locationFile;
			locationFile.open("Locations.txt");
			string fileLocation;
			bool locationFound = false;

			locationFile >> fileLocation;
			do
			{
				if (fileLocation == locationVisited)
				{
					locationFound = true;
				}

				locationFile >> fileLocation;

			} while (!locationFile.fail());

			locationFile.close();


			if (!locationFound)
			{

				locationFile.open("Locations.txt", ios::app);
				locationFile << locationVisited << endl;
				locationFile.close();


			}

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


