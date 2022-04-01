#include <iostream>
#include<string>
#include<cstring>
#include<algorithm>
using namespace std;
int main() {
    bool flag=1;
    bool check=0;
    int key;
    int x;
    string sentence;
    while (flag=1) {
        cout << "enter 1 if you want to encrypt or 2 if you want to decrypt any other key to close"<<endl;
        cin >> x;
        if (x!=1 && x!=2){
            cout<<"thanks for using our system"<<endl;
            break;
        }
        cout << "enter the key number " << endl;
        cin >> key;
        for(int t=0;t<t+1;t++)
        {
            if (key>0&&key<10){
                break;
            }
            else{
                cout<< "valid key"<<endl<<"enter number from 1 to 9"<<endl;
                cin.clear();
                cin.sync();
                cin>> key;
            }

        }
        cout << "enter the sentence" << endl;
        cin.clear();
        cin.sync();
        getline(cin, sentence);
        sentence.erase(remove(sentence.begin(), sentence.end(), ' '), sentence.end());
        char encrypted[key][sentence.length()];

        for (int row = 0; row < key; row++) {
            for (int column = 0; column < sentence.length(); column++) {
                encrypted[row][column] = '.';
            }
        }

        if (x == 1) {
            string encryption;
            int n = 1, m = key - 2;
            for (int i = 0; i < sentence.length(); i++) {
                if (i == 0) {
                    encrypted[0][0] = sentence[0];
                } else if (n < key) {
                    m = key - 2;
                    for (int x = n; x < key; x++) {
                        encrypted[x][i] = sentence[i];
                        n++;
                        break;
                    }


                } else {
                    for (int k = m; k >= 0; k--) {
                        encrypted[k][i] = sentence[i];
                        if (m == 0) {
                            n = m + 1;
                        }
                        m--;
                        break;
                    }

                }
            }
            for (int l = 0; l < key; l++) {
                for (int x = 0; x < sentence.length(); x++) {
                    if (encrypted[l][x] != '.') {
                        encryption += encrypted[l][x];
                    }
                }
            }

            cout << endl;
            cout << "the encryption is :  "<< encryption<<endl<<endl<<endl;
        }
        if (x == 2) {
            string encryption;
            int n = 1, m = key - 2;
            for (int i = 0; i < sentence.length(); i++) {
                if (i == 0) {
                    encrypted[0][0] = '-';
                } else if (n < key) {
                    m = key - 2;
                    for (int x = n; x < key; x++) {
                        encrypted[x][i] = '-';
                        n++;
                        break;
                    }


                } else {
                    for (int k = m; k >= 0; k--) {
                        encrypted[k][i] = '-';
                        if (m == 0) {
                            n = m + 1;
                        }
                        m--;
                        break;
                    }

                }
            }
            bool check2 = 0;
            for (int g = 0; g < sentence.length(); g++) {
                check2 = 0;
                for (int p = 0; p < key; p++) {
                    if (check2 == 1) {
                        break;
                    }
                    for (int v = 0; v < sentence.length(); v++) {
                        if (encrypted[p][v] == '-') {
                            encrypted[p][v] = sentence[g];
                            check2 = 1;
                            break;

                        }
                    }
                }

            }
            for (int j = 0; j < sentence.length(); j++) {

                for (int i = 0; i < key; i++) {
                    if (encrypted[i][j] != '.')
                        encryption += encrypted[i][j];


                }
            }
            cout << endl;
            cout << "the decryption is :  "<< encryption<<endl<<endl<<endl;


        }
    }
}






