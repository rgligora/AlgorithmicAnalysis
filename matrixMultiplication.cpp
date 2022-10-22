#include <iostream>
#include <random>
#include <string>
#include <sstream>
#include <iomanip>


using namespace std;

void randomMatrixGen(long *polje, long index){

    std::random_device rd; // obtain a random number from hardware
    std::mt19937 gen(rd()); // seed the generator
    std::uniform_int_distribution<> distr(1, 10); // define the range

        for (int i = 0; i < index; i++)
        {
            polje[i] = distr(gen); //fills the matrix with random elements in the desired range
        }
}

void printMatrix(long *arr, long numbOfElements){
/*prints the matrix in the formatted way so that each element of the matrix is printed with 4 spaces*/

    long dim = sqrt(numbOfElements);
     
    for (long i = 0; i < numbOfElements; i++) 
    {
        if((i+1) % dim == 0){
            cout << std::setw(4) <<arr[i] << "\n";
        } else {
            cout << std::setw(4) << arr[i] << " ";
        }
    }
    cout << endl;
    
}

void multiply(long *arr1, long *arr2, long *resultArr, long numbOfElements){
    /*the function multiplies two given matricies and saves them in the array resultArr*/

    long dim = sqrt(numbOfElements);
    long temp = 0;
    long h = 0;

    for(int i = 0; i < dim; i++){
        
        for(int j = 0; j < dim; j++){
            for(int k = 0; k < dim; k++){
                temp += (arr1[i*(dim) + k] * arr2[j + (k * dim)]);
            }
            resultArr[h] = temp;
            ++h;
            temp = 0;
        }        
    }

}


int main(){

    long matrixDim ;
    cout << "Type simetrical matrix dimension > ";
    cin >> matrixDim;

    long numbElements = matrixDim * matrixDim;
    
    long arr1[numbElements], arr2[numbElements], resultArray[numbElements];
    long *p1 = arr1;
    long *p2 = arr2;
    long *rp = resultArray;

    randomMatrixGen(p1, numbElements); 
    randomMatrixGen(p2, numbElements);

    printMatrix(p1, numbElements);

    cout << endl;

    printMatrix(p2, numbElements);

    multiply(p1, p2, rp, numbElements);

    printMatrix(rp, numbElements);

      

    return 0;
}