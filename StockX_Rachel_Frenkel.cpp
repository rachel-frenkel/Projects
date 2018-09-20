#include <iostream>
#include <getopt.h>
using namespace std;

bool getFlags(int argc, char * argv[]) {
    bool interact = false;

    opterr = true;
    int choice;
    int option_index = 0;
    option long_options[] =
    {
        {"interact", no_argument, nullptr, 'i'},
        {nullptr, 0,                 nullptr, '\0'} 
    };
    
    while ((choice = getopt_long(argc, argv, "i", long_options, &option_index)) != -1) { 
        switch (choice) {
            case 'i':
            	return true;
                
            default:
                return false;
        } 
    }
}


int main(int argc, char * argv[]) {
	cout << "If you want to interact with the program, in the command line, add a --interact/-i to "; 
	cout << "be able to the tell the program if the code is right or wrong" << endl;

	bool correctPin = false;  /*the user will be able to input into the terminal and tell 
								the computer whether the code output is correct or not*/
	bool interact = getFlags(argc, argv); /* the user can decide if they want to be able to give the 
								right or wrong answer everytime a new code is tried or if they just
								want them all to auto-generate*/

	for(int i = 0; i < 10; ++i) {
		for(int j = 0; j < 10; ++j) {
			for(int k = 0; k < 10; ++k) {
				for(int m = 0; m < 10; ++m) {
					if(!correctPin) {
						cout << i << " " << j << " " << k << " " << m << endl;
						if(interact) {
							cout << "Is this the right pin? (Put 0 for false and 1 for true): ";
							cin >> correctPin;
						}
					}
					else
						break;
				}
			}
		}
	}

	return 0;
}