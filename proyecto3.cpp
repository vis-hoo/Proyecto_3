#include <chrono>
#include <iostream>
#include <time.h>
#include <vector>
using namespace std;
using namespace chrono;

// VALOR ORIGINAL / 4
#define SCOREBOARD_MIN 22500//90000
#define SCOREBOARD_MAX 25000//100000
#define VILLAGEPATH_MIN 12500//50000
#define VILLAGEPATH_MAX 17500//70000
#define RENDERING_MIN 125//500
#define RENDERING_MAX 250//1000

bool menu();
void initializeRandom(vector<int> *random, int n);
void initializeDuplicateRandom(vector<int> *duplicateRandom, int n);
void initializeSorted(vector<int> *sorted, int n);
void initializeReversed(vector<int> *reversed, int n);
void selectionSort(vector<int> *data, int n, bool ascendente);
void bubbleSort(vector<int> *data, int n, bool ascendente);
void insertionSort(vector<int> *data, int n, bool ascendente);
void swap(vector<int> *data, int i, int j);
int getGap(int n);
void shellSort(vector<int> *data, int n, bool ascendente);
void racing(vector<int> *array1, vector<int> *array2, vector<int> *array3, vector<int> *array4, int n, bool ascendente, string carrera);
int intInput(string msg, int min, int max);

int main(){
    srand(time(NULL));

    int trash = rand();
    int scoreBoard_amount = (rand() % (SCOREBOARD_MAX - SCOREBOARD_MIN + 1)) + SCOREBOARD_MIN;
    int villagePath_amount = (rand() % (VILLAGEPATH_MAX - VILLAGEPATH_MIN + 1)) + VILLAGEPATH_MIN;
    int rendering_amount = ((rand() % (RENDERING_MAX - RENDERING_MIN + 1)) + RENDERING_MIN) * 15;
    
    bool ascendente = menu();

#pragma region Tablero de Puntajes
    // Set de datos aleatorio
    vector<int> *scoreBoard_Random1 = new vector<int>;
    initializeRandom(scoreBoard_Random1, scoreBoard_amount);
    vector<int> scoreBoard_Random2 = *scoreBoard_Random1;
    vector<int> scoreBoard_Random3 = *scoreBoard_Random1;
    vector<int> scoreBoard_Random4 = *scoreBoard_Random1;
    // Set de datos aleatorio con duplicados
    vector<int> *scoreBoard_DuplicateRandom1 = new vector<int>;
    initializeDuplicateRandom(scoreBoard_DuplicateRandom1, scoreBoard_amount);
    vector<int> scoreBoard_DuplicateRandom2 = *scoreBoard_DuplicateRandom1;
    vector<int> scoreBoard_DuplicateRandom3 = *scoreBoard_DuplicateRandom1;
    vector<int> scoreBoard_DuplicateRandom4 = *scoreBoard_DuplicateRandom1;
    // Set de datos ordenado
    vector<int> *scoreBoard_Sorted1 = new vector<int>;
    initializeSorted(scoreBoard_Sorted1, scoreBoard_amount);
    vector<int> scoreBoard_Sorted2 = *scoreBoard_Sorted1;
    vector<int> scoreBoard_Sorted3 = *scoreBoard_Sorted1;
    vector<int> scoreBoard_Sorted4 = *scoreBoard_Sorted1;
    // Set de datos inverso
    vector<int> *scoreBoard_Reversed1 = new vector<int>;
    initializeReversed(scoreBoard_Reversed1, scoreBoard_amount);
    vector<int> scoreBoard_Reversed2 = *scoreBoard_Reversed1;
    vector<int> scoreBoard_Reversed3 = *scoreBoard_Reversed1;
    vector<int> scoreBoard_Reversed4 = *scoreBoard_Reversed1;
#pragma endregion

#pragma region Caminos entre Aldeas
    // Set de datos aleatorio
    vector<int> *villagePath_Random1 = new vector<int>;
    initializeRandom(villagePath_Random1, villagePath_amount);
    vector<int> villagePath_Random2 = *villagePath_Random1;
    vector<int> villagePath_Random3 = *villagePath_Random1;
    vector<int> villagePath_Random4 = *villagePath_Random1;
    // Set de datos aleatorio con duplicados
    vector<int> *villagePath_DuplicateRandom1 = new vector<int>;
    initializeDuplicateRandom(villagePath_DuplicateRandom1, villagePath_amount);
    vector<int> villagePath_DuplicateRandom2 = *villagePath_DuplicateRandom1;
    vector<int> villagePath_DuplicateRandom3 = *villagePath_DuplicateRandom1;
    vector<int> villagePath_DuplicateRandom4 = *villagePath_DuplicateRandom1;
    // Set de datos ordenado
    vector<int> *villagePath_Sorted1 = new vector<int>;
    initializeSorted(villagePath_Sorted1, villagePath_amount);
    vector<int> villagePath_Sorted2 = *villagePath_Sorted1;
    vector<int> villagePath_Sorted3 = *villagePath_Sorted1;
    vector<int> villagePath_Sorted4 = *villagePath_Sorted1;
    // Set de datos inverso
    vector<int> *villagePath_Reversed1 = new vector<int>;
    initializeReversed(villagePath_Reversed1, villagePath_amount);
    vector<int> villagePath_Reversed2 = *villagePath_Reversed1;
    vector<int> villagePath_Reversed3 = *villagePath_Reversed1;
    vector<int> villagePath_Reversed4 = *villagePath_Reversed1;
#pragma endregion
    
#pragma region Renderizado de Objetos
    // Set de datos aleatorio
    vector<int> *rendering_Random1 = new vector<int>;
    initializeRandom(rendering_Random1, rendering_amount);
    vector<int> rendering_Random2 = *rendering_Random1;
    vector<int> rendering_Random3 = *rendering_Random1;
    vector<int> rendering_Random4 = *rendering_Random1;
    // Set de datos aleatorio con duplicados
    vector<int> *rendering_DuplicateRandom1 = new vector<int>;
    initializeDuplicateRandom(rendering_DuplicateRandom1, rendering_amount);
    vector<int> rendering_DuplicateRandom2 = *rendering_DuplicateRandom1;
    vector<int> rendering_DuplicateRandom3 = *rendering_DuplicateRandom1;
    vector<int> rendering_DuplicateRandom4 = *rendering_DuplicateRandom1;
    // Set de datos ordenado
    vector<int> *rendering_Sorted1 = new vector<int>;
    initializeSorted(rendering_Sorted1, rendering_amount);
    vector<int> rendering_Sorted2 = *rendering_Sorted1;
    vector<int> rendering_Sorted3 = *rendering_Sorted1;
    vector<int> rendering_Sorted4 = *rendering_Sorted1;
    // Set de datos inverso
    vector<int> *rendering_Reversed1 = new vector<int>;
    initializeReversed(rendering_Reversed1, rendering_amount);
    vector<int> rendering_Reversed2 = *rendering_Reversed1;
    vector<int> rendering_Reversed3 = *rendering_Reversed1;
    vector<int> rendering_Reversed4 = *rendering_Reversed1;
#pragma endregion

#pragma region Carreras de Algoritmos
    racing(scoreBoard_Random1, &scoreBoard_Random2, &scoreBoard_Random3, &scoreBoard_Random4, scoreBoard_amount, ascendente, "Tablero: Modo Aleatorio");
    racing(scoreBoard_DuplicateRandom1, &scoreBoard_DuplicateRandom2, &scoreBoard_DuplicateRandom3, &scoreBoard_DuplicateRandom4, scoreBoard_amount, ascendente, "Tablero: Modo Aleatorio con Duplicados");
    racing(scoreBoard_Sorted1, &scoreBoard_Sorted2, &scoreBoard_Sorted3, &scoreBoard_Sorted4, scoreBoard_amount, ascendente, "Tablero: Modo Ascendente");
    racing(scoreBoard_Reversed1, &scoreBoard_Reversed2, &scoreBoard_Reversed3, &scoreBoard_Reversed4, scoreBoard_amount, ascendente, "Tablero: Modo Descendente");

    racing(villagePath_Random1, &villagePath_Random2, &villagePath_Random3, &villagePath_Random4, villagePath_amount, ascendente, "Camino de Aldeas: Modo Aleatorio");
    racing(villagePath_DuplicateRandom1, &villagePath_DuplicateRandom2, &villagePath_DuplicateRandom3, &villagePath_DuplicateRandom4, villagePath_amount, ascendente, "Camino de Aldeas: Modo Aleatorio con Duplicados");
    racing(villagePath_Sorted1, &villagePath_Sorted2, &villagePath_Sorted3, &villagePath_Sorted4, villagePath_amount, ascendente, "Camino de Aldeas: Modo Ascendente");
    racing(villagePath_Reversed1, &villagePath_Reversed2, &villagePath_Reversed3, &villagePath_Reversed4, villagePath_amount, ascendente, "Camino de Aldeas: Modo Descendente");

    racing(rendering_Random1, &rendering_Random2, &rendering_Random3, &rendering_Random4, rendering_amount, ascendente, "Objetos: Modo Aleatorio");
    racing(rendering_DuplicateRandom1, &rendering_DuplicateRandom2, &rendering_DuplicateRandom3, &rendering_DuplicateRandom4, rendering_amount, ascendente, "Objetos: Modo Aleatorio con Duplicados");
    racing(rendering_Sorted1, &rendering_Sorted2, &rendering_Sorted3, &rendering_Sorted4, rendering_amount, ascendente, "Objetos: Modo Ascendente");
    racing(rendering_Reversed1, &rendering_Reversed2, &rendering_Reversed3, &rendering_Reversed4, rendering_amount, ascendente, "Objetos: Modo Descendente");
#pragma endregion
    return 0;
}

//Función que imprime el menú principal.
//Retorna si los valores deben ser ordenados de manera ascendente o descendente.
bool menu(){
    cout << "\n\nCarreras de Algoritmos";
    cout << "\n\n1. Ascendente.";
    cout << "\n2. Descendente.";
    int opt = intInput("\n\nOpcion elegida: ", 1, 2);
    if(opt == 1) return true;
    else return false;
}

#pragma region Vector Inicialization
//Función que inicializa un vector con valores aleatorios, sin repeticiones.
//Recibe como parámetros un puntero a un vector y el valor total de elementos.
void initializeRandom(vector<int> *random, int n){
    vector<int> &array = *random;
    for(int i = 0; i < n; i++){
        int r;
        bool available = false;
        while(!available){
            r = (rand() % n) + 1;
            if(array.size() == 0) available = true;
            else
                for(int j = 0; j < array.size(); j++){
                    if(r == array[j]) break;
                    else if(j + 1 == array.size()) available = true;
                }
        }
        array.push_back(r);
    }
}

//Función que inicializa un vector con valores aleatorios repetidos.
//Recibe como parámetros un puntero a un vector y el valor total de elementos.
void initializeDuplicateRandom(vector<int> *duplicateRandom, int n){
    vector<int> &array = *duplicateRandom;
    for(int i = 0; i < n; i++){
        int r = (rand() % n) + 1;
        array.push_back(r);
    }
}

//Función que inicializa un vector con valores ordenados de manera ascendente, sin repeticiones.
//Recibe como parámetros un puntero a un vector y el valor total de elementos.
void initializeSorted(vector<int> *sorted, int n){
    vector<int> &array = *sorted;
    for(int i = 0; i < n; i++) array.push_back(i + 1);
}

//Función que inicializa un vector con valores ordenados de manera descendente, sin repeticiones.
//Recibe como parámetros un puntero a un vector y el valor total de elementos.
void initializeReversed(vector<int> *reversed, int n){
    vector<int> &array = *reversed;
    for(int i = n; i > 0; i--) array.push_back(i);
}
#pragma endregion

#pragma region Sorting Algortithms
//Función que aplica el algoritmo Selection Sort al grupo de valores.
//Recibe como parámetros un puntero a un vector, el valor total de elementos, y el tipo de orden de los elementos.
void selectionSort(vector<int> *data, int n, bool ascendente){
    vector<int> &array = *data;
    for(int i = 0; i < n; i++)
        for(int j = (i + 1); j < n; j++){
            if(ascendente && array[j] < array[i]) swap(&array, i, j);
            else if(!ascendente && array[j] > array[i]) swap(&array, i, j);
        }
}

//Función que aplica el algoritmo Bubble Sort al grupo de valores.
//Recibe como parámetros un puntero a un vector, el valor total de elementos, y el tipo de orden de los elementos.
void bubbleSort(vector<int> *data, int n, bool ascendente){
    vector<int> &array = *data;
    for(int i = 1; i < n; i++)
        for(int j = 0; j < (n - i); j++){
            if(ascendente && array[j] > array[j + 1]) swap(&array, j, (j + 1));
            else if(!ascendente && array[j] < array[j + 1]) swap(&array, j, (j + 1));
        }
}

//Función que aplica el algoritmo Insertion Sort al grupo de valores.
//Recibe como parámetros un puntero a un vector, el valor total de elementos, y el tipo de orden de los elementos.
void insertionSort(vector<int> *data, int n, bool ascendente){
    vector<int> &array = *data;
    for(int i = 1; i < n; i++){
        int j = i;
        if(ascendente)
            while(j > 0 && array[j - 1] > array[j]){
                swap(&array, j, (j - 1));
                j = (j - 1);
            }
        else
            while(j > 0 && array[j - 1] < array[j]){
                swap(&array, j, (j - 1));
                j = (j - 1);
            }
    }
}

//Función que intercambia la posición de dos valores en un grupo de valores.
//Recibe como parámetros un puntero a un vector y la posición de los 2 valores a intercambiar.
void swap(vector<int> *data, int i, int j){
    vector<int> &array = *data;
    int temp = array[i];
    array[i] = array[j];
    array[j] = temp;
}

//Función que retorna el valor del Knuth Gap para el algoritmo Shell Sort.
//Recibe como parámetros el valor total de elementos.
int getGap(int n){
    int gap = 0;
    while ((3 * gap) + 1 < n) gap = (3 * gap) + 1;
    return gap;
}

//Función que aplica el algoritmo Shell Sort al grupo de valores.
//Recibe como parámetros un puntero a un vector, el valor total de elementos, y el tipo de orden de los elementos.
void shellSort(vector<int> *data, int n, bool ascendente){
    vector<int> &array = *data;
    int gap = getGap(n);
    while (gap > 0){
        for (int i = gap; i < n; i++){
                int temp = array[i];
                int j = i;
                if (ascendente)
                    while (j >= gap && array[j - gap] > temp){
                        array[j] = array[j - gap];
                        j = j - gap;
                    }
                else
                    while (j >= gap && array[j - gap] < temp){
                        array[j] = array[j - gap];
                        j = j - gap;
                    }
                array[j] = temp;
        }
        gap = getGap(gap);
    }
}
#pragma endregion

//Función que ejecuta las carreras.
//Recibe como parámetros 4 punteros a vectores, el valor total de elementos, el tipo de orden de los elementos, y el tipo de carrera.
void racing(vector<int> *array1, vector<int> *array2, vector<int> *array3, vector<int> *array4, int n, bool ascendente, string carrera){
    double times[4];

    auto start = high_resolution_clock::now();
    selectionSort(array1, n, ascendente);
    auto end = high_resolution_clock::now();
    auto time_taken = duration_cast<duration<double>>(end - start);
    times[0] = time_taken.count();

    start = high_resolution_clock::now();
    bubbleSort(array2, n, ascendente);
    end = high_resolution_clock::now();
    time_taken = duration_cast<duration<double>>(end - start);
    times[1] = time_taken.count();

    start = high_resolution_clock::now();
    insertionSort(array3, n, ascendente);
    end = high_resolution_clock::now();
    time_taken = duration_cast<duration<double>>(end - start);
    times[2] = time_taken.count();

    start = high_resolution_clock::now();
    shellSort(array4, n, ascendente);
    end = high_resolution_clock::now();
    time_taken = duration_cast<duration<double>>(end - start);
    times[3] = time_taken.count();

    cout << "\n\nCarrera por el " << carrera;
    cout << "\n  1. Selection Sort: " << times[0] << " segundos.";
    cout << "\n  2. Bubble Sort: " << times[1] << " segundos.";
    cout << "\n  3. Insertion Sort: " << times[2] << " segundos.";
    cout << "\n  4. Shell Sort: " << times[3] << " segundos.";

    int winner_index = 0;
    for(int i = 0; i < 4; i++) if (times[i] < times[winner_index]) winner_index = i;
    cout << "\nEl ganador es: ";
    if(winner_index == 0) cout << "Selection Sort ";
    else if(winner_index == 1) cout << "Bubble Sort ";
    else if(winner_index == 2) cout << "Insertion Sort ";
    else cout << "Shell Sort ";
    cout << "con " << times[winner_index] << " segundos.";
}

//Función auxiliar que retorna un valor dentro de un rango.
//Recibe como parámetros el texto, el mínimo y el máximo del rango.
int intInput(string msg, int min, int max){
    int opt;
    do{
        cout << msg;
        cin >> opt;
        if (cin.good() && opt >= min && opt <= max) return opt;
        else{
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            cout << "*Ingresa un valor dentro del rango.";
        }
    }while(1);
}
