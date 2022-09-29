#include <stdio.h>
#include "tree.h"
#include <fstream>
#include <iostream>
using namespace std;

int main()
{
    BinaryTree tree;
    
    // Open files
    ifstream din;
    ofstream dout;
    
    // Local variables
    string rake;
    string searchKey;
    string number;
    string street;
    string city;
    string state;
    string zip;
    int action = 0;
    while(action != 5)
    {
        cout << " ------BST Menu------" << endl;
        cout << " 1 - Insert address\n 2 - Search address\n 3 - Print BST height\n 4 - Print BST to file\n 5 - Quit program" << endl;
        
        cin >> action;
        
        if(action == 1)
        {
            int act;
            cout << " 1 - Insert single address\n 2 - Insert address from file" << endl;
            
            cin >> act;
            
            if(act == 1)
            {
                getline(cin, rake);
                string _searchKey;
                string _number;
                string _street;
                string _city;
                string _state;
                string _zip;
                cout << " Enter house number: ";
                getline(cin, _number);
                cout << " Enter street name: ";
                getline(cin, _street);
                cout << " Enter city name: ";
                getline(cin, _city);
                cout << " Enter state name: ";
                getline(cin, _state);
                cout << " Enter ZIP code: ";
                getline(cin, _zip);
                
                _searchKey = _city + _street;
                
                tree.Insert(_searchKey, _number, _street, _city, _state, _zip);
            }
            else if(act == 2)
            {
                getline(cin, rake);
                string file;
                cout << " Enter file name: ";
                getline(cin, file);
                din.open(file);
                // Loop reading input file
                while (!din.eof())
                {
                    /*
                    // Extract street name
                    getline(din, street);
                    int pos = 0;
                    while (pos < street.length() && street[pos] == ' ')
                        pos++;
                    street = street.substr(pos);
                    
                    // Read and extract city, state, zip
                    getline(din, city);
                    pos = city.find(", ");
                    if (pos > 0)
                    {
                        state = city.substr(pos+2);
                        city.erase(pos);
                        pos = state.find(' ');
                        if (pos > 0)
                        {
                            zip = state.substr(pos+1);
                            state.erase(pos);
                        }
                    }
                    */
                    
                    getline(din, number);
                    getline(din, street);
                    getline(din, city);
                    getline(din, state);
                    getline(din, zip);
                    getline(din, rake);
                    
                    //Create searchKey
                    searchKey = city + street;
                    
                    //Insert address
                    tree.Insert(searchKey, number, street, city, state, zip);
                }
                //Print tree
                tree.Print();
            }
        }
        else if(action == 2)
        {
            string fake;
            getline(cin, fake);
            string city_name;
            string street_name;
            string sudoSearchKey;
            
            //Get street, address input from user
            cout << " Enter city name: ";
            getline(cin, city_name);
            cout << "\n Enter street name:";
            getline(cin, street_name);
            
            //Combine
            sudoSearchKey = city_name + street_name;
            
            if(tree.Search(sudoSearchKey))
            {
                cout << "" << endl;
            }
            else if(!tree.Search(sudoSearchKey))
            {
                cout << "\n Address not found.\n" << endl;
            }
        }
        //Height method not working----------------------------
        else if(action == 3)
        {
            int tall = 0;
            tall = tree.helper();
            cout << " Height: " << tall << "\n" << endl;
        }
        else if(action == 4)
        {
            cout << " Tree printed to sorted_address.txt, output will display upon exiting program." << endl;
            tree.Print();
        }
        else if(action == 5)
        {
            din.close();
            dout.close();
            return 0;
        }
        action = 0;
    }
}
