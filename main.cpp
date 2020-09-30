#include <iostream>
#include <string>//importing header files
#include <tuple>

//test (ignore this)
using namespace std;

void printList(double* lst, int len){

    int i;
    cout << "\n";
    for (i = 0; i < len; i++) {

    cout << "\n" << lst[i];

}

}

std::tuple<double, double> gd(int batches, int samples, double *x, double *yh, double a, double w, double b, double dw, double db){

        //repeat batch amount of times
    for(int i = 0; i < batches; i++){

        //Since this code runs on 1 core, we use nested for loops
        //calculate derivative (With MSE loss):
        //-dw = 2 * x * (yh - yp)
        //-db = 2 * (yh - yp)
        dw = 0;
        for(int j=0; j<samples; j++){

            dw += 2 * x[j] * (yh[j] - (x[j] * w + b)); //The last part (x * w + b) is the main function
            db += 2 * (yh[j] - (x[j] * w + b));

        }

        dw /= samples; //average the sums
        db /= samples;
        w += a * dw; b += a * db; //multiply by the learning rate. Note, since we calculated, -dw instead of dw, we add instead of subtract
        cout << endl << w; //verbose, comment to turn off
        cout << endl << b; //same here

    }
    return {w, b};
}

int main()
{
    cout.precision(10);
    double w = 10; //weight
    double b = 0; //bias
    int samples = 5;
    double dw = 0;
    double db = 0;
    int batches = 10;
    double a = 0.01; //learning rate
    double *x, *yh;
    x = new double[samples];
    yh = new double[samples];

    //set x = {1, 2, 3, 4, 5} and y = {2, 4, 6, 8, 10}. Change as nessesary
    for(int i = 0; i<samples; i++){

    x[i] = i+1;
    yh[i] = 2*i + 2;

    }
    cout << "X:";
    printList(x, samples);
    cout << endl << endl << "^\nY:";
    printList(yh, samples);

    std::tuple<double, double> vals;
    vals = gd(batches, samples, x, yh, a, w, b, dw, db);
    w = std::get<0>(vals);
    b = std::get<1>(vals);
    //cout << "fin: " << w << " " << b;
    //take input
    string cmnd = "";
    while(true){

        cout << endl;
        std::getline(std::cin, cmnd);
        //cout << cmnd;
        int split = cmnd.find(" ");
        string s1 = cmnd.substr(0, split);
        //cout << split;
        string r = cmnd.substr(split + 1);
        if(s1 == "end"){

            break;

        }
        if(s1 == "btrain"){

            batches = stoi(r);
            std::tuple<double, double> vals;
            vals = gd(batches, samples, x, yh, a, w, b, dw, db);
            w = std::get<0>(vals);
            b = std::get<1>(vals);

        }

        if(s1 == "eval"){

            cout << (w * stoi(r) + b);

        }

        if(s1 == "edit"){

            if(r[0] == '-' && r[1] == 'i'){

                //edit single index: todo
                cout << "you typed 'edit -i'";

            }
            //int rplit = r.find(" ");
            //string r1 = r.substr(0, rplit);
            //string r2 = r.substr(rplit);
            if(r == "x"){

                double bar;
                for(int foo = 0; foo<samples; foo++){

                    cout << endl << "Enter Number " << (foo + 1) << endl << ">>> ";
                    cin >> bar;
                    x[foo] = bar;

                }
                printList(x, samples);

            }

            if(r == "y"){

                double bar;
                for(int foo = 0; foo<samples; foo++){

                    cout << endl << "Enter Number " << (foo + 1) << endl << ">>> ";
                    cin >> bar;
                    yh[foo] = bar;

                }
                printList(yh, samples);

            }

            if(r == "samples"){

                cout << endl << "Enter number of samples: " << endl << ">>> ";
                cin >> samples;
                cout << endl << "There are now " << samples << " samples." << endl << "WARNING, MAKE SURE TO CHANGE 'x' AND 'y' USING 'edit x' and 'edit y'";

            }

        }

        if(s1 == "print"){
        cout.precision(10);

            if(r == "x"){

                cout << "x:";
                printList(x, samples);

            }

            if(r == "y"){

                cout << "y:";
                printList(yh, samples);

            }

            if(r == "w"){

                cout << "w:" << endl << w;

            }
            if(r == "b"){

                cout << "b:" << endl << b;

            }
            if(r == "dw"){

                cout << "dw:" << endl << dw;

            }
            if(r == "db"){

                cout << "db:" << endl << db;

            }
            if(r == "samples"){

                cout << "samples:" << endl << samples;

            }

        }

    }

    return 0;
}
