#include <iostream>
#include <fstream>
#include "Station.h"
#include "Stack.h"
#include "Item.h"

std::fstream getFile(std::string name)
{
    std::fstream file(name);
    return file;
}

Station** createStations(std::fstream &file, int size)
{
    Station** stations;
    stations = new Station*[size];
    std::string buffer;

    for (int i = 0; i < size; ++i) {
        getline(file, buffer);
        stations[i] = new Station(buffer.substr(0, buffer.find(" ")), stoi(buffer.substr(buffer.find(" ") + 1, buffer.size())));
    }

    return stations;
}

void insertionSort(Station** &stations, int size)
{
    int j;
    Station* keyStation;
    for (int i = 1; i < size; i++)
    {
        keyStation = stations[i];
        j = i - 1;
        while (j >= 0 && stations[j]->getDistance() > keyStation->getDistance())
        {
            stations[j + 1] = stations[j];
            j = j - 1;
        }
        stations[j + 1] = keyStation;
    }
}

void partition(Station** stations, int start, int end, int *i, int *j)
{
    Station* pivot;
    Station* aux;
    *i = start;
    *j = end;
    pivot = stations[(*i + *j) / 2];
    do {
        while (pivot->getDistance() > stations[*i]->getDistance()) (*i)++;
        while (pivot->getDistance() < stations[*j]->getDistance()) (*j)--;
        if (*i <= *j) {
            aux = stations[*i];
            stations[*i] = stations[*j];
            stations[*j] = aux;
            (*i)++;
            (*j)--;
        }
    } while (*i <= *j);
}

void quickSort(Station** stations, int start, int end)
{
    int i, j;
    partition(stations, start, end, &i, &j);
    if (start < j) quickSort(stations, start, j);
    if (i < end) quickSort(stations, i, end);
}

void merge(Station** &stations, int start, int middle, int end)
{
    int n1 = middle - start + 1;
    int n2 = end - middle;

    Station** startStations = new Station*[n1];
    Station** endStations = new Station*[n2];
 
    for (int i = 0; i < n1; i++)
        startStations[i] = stations[start + i];
    for (int i = 0; i < n2; i++)
        endStations[i] = stations[middle + 1 + i];

    int i = 0;
    int j = 0;
    int k = start;

    while (i < n1 && j < n2) {
        if (startStations[i]->getDistance() <= endStations[j]->getDistance()) {
            stations[k] = startStations[i];
            i++;
        } else {
            stations[k] = endStations[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        stations[k] = startStations[i];
        i++;
        k++;
    }

    while (j < n2) {
        stations[k] = endStations[j];
        j++;
        k++;
    }

    delete startStations;
    delete endStations;
}
 
void mergeSort(Station** &stations, int start, int end)
{
    if (start >= end) {
        return;
    }
    int middle = start + (end - start) / 2;
    mergeSort(stations, start, middle);
    mergeSort(stations, middle + 1, end);
    merge(stations, start, middle, end);
}
 
void modifiedQuickSort(Station** &stations, int size)
{
    Stack<Item> stack;
    Item item;
    int start, end, i, j;
    start = 0;
    end = size - 1;
    item.end = end;
    item.start = start;
    stack.add(item);
    do {
        if (end > start) {
            partition(stations, start, end, &i, &j);
            if ((j - start) > (end - i)) {
                item.end = j;
                item.start = start;
                stack.add(item);
                start = i;
            } else {
                item.start = i;
                item.end = end;
                stack.add(item);
                end = j;
            }
        } else {
            item = stack.remove();
            end = item.end;
            start = item.start;
        }
    } while (!stack.empty());
}

void combSort(Station** &stations, int size)
{
    int gap = size;
    double shrink = 1.3;
    bool swapped = false;
    int i;
    Station* t;
    while (gap != 1 || swapped) {
        gap = (int) (gap / shrink);
        if (gap < 1) {
            gap = 1;
        }
        i = 0;
        swapped = false;
        while (i + gap < size) {
            if (stations[i]->getDistance() > stations[i + gap]->getDistance()) {
                t = stations[i];
                stations[i] = stations[i + gap];
                stations[i + gap] = t;
                swapped = true;
            }
            i++;
        }
    }
}

int main(int argc, char* argv[]) {
    int size = atoi(argv[2]);
    std::fstream dataFile = getFile(std::string(argv[1]));
    Station** stations = createStations(dataFile, size);
    // insertionSort(stations, size);
    quickSort(stations, 0, size - 1);
    // mergeSort(stations, 0, size - 1);
    // modifiedQuickSort(stations, size);
    // combSort(stations, size);

    for (int i = size - 1; i >= size - 7; --i) {
        std::cout << stations[i]->getName() << " " << stations[i]->getDistance() << std::endl;
    }

    for (int i = 0; i < size; ++i) {
        delete stations[i];
    }
    delete stations;
    return 0;
}
