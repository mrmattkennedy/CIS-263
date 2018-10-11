#ifndef AUDS_GUARD
#define AUDS_GUARD
#include <cstdlib>
#include <algorithm>
#include <iostream>

template <typename T>
/**********************************************************************
 * AUDS (Almost Useless Data Structure) for CIS 263. Acts as a
 * dynamically resizable array, with a random pop method.
 *
 * @author Matt Kennedy
 * @version Winter 2018
 * *******************************************************************/
class AUDS {

//Public section of the class.
public:
	/**************************************************************
 	* Default constructor.
 	* Initializes size to 100.
 	* Initialize data as an array of type T and size 100.
 	* Initializes currenetSpot to 0.
 	* ************************************************************/
	AUDS() {
	//	dataSize = 100;
		data = new T[dataSize];
		currentSpot = 0;
		actualSize = 0;
	}
	
	/**************************************************************
 	* Copy constructor. Does a "deep copy" of an object passed in.
 	*
 	* @param &other Reference to the other object to make a copy of.
 	* ************************************************************/
	AUDS(const AUDS &other) {
		dataSize = other.dataSize;
		currentSpot = other.currentSpot;
		data = new T[dataSize];
		actualSize = other.actualSize;

		for (int i = 0; i < dataSize; i++) {
			data[i] = other.data[i];
		}
	
	}
	
	/**************************************************************
 	* Equals operator method. Passes other in by value, which
 	* means a copy of other is made using the copy constructor.
 	* After the copy is made, the data from it is swapped to this,
 	* then when the function is done, the local copy is deleted.
 	*
 	* @param other The other AUDS object, passed by value.
 	* @return AUDS& Passes a refernece to the new AUDS back.
 	* ************************************************************/
	AUDS& operator=(AUDS other) {
		std::swap(data, other.data);
		std::swap(dataSize, other.dataSize);
		std::swap(currentSpot, other.currentSpot);
		std::swap(actualSize, other.actualSize);
		
		return *this;
	}

	T& operator[] (const int index) {
		return data[index];
	}
	
	/**************************************************************
 	* Destructor. Deletes memory from wherever it is stored.
 	* ************************************************************/
	~AUDS() {
		delete[] data;
	}

	/**************************************************************
 	* Returns the current size of the array.
 	*
 	* @return The current size.
 	* ************************************************************/
	int getSize() {
		return dataSize;
	}

	int size() {
		return actualSize;
	}

	/**************************************************************
 	* Adds an element to the array. Resizes if necessary.
 	*
 	* @param The element to add
 	* (Note: the elem is not by reference because we simply want a
 	* copy of the variable to add to the array. We don't need to
 	* change or edit the value. This note is for me, sorry
 	* Professor Woodring!)
 	* ************************************************************/
	void push(T elem) {
		if (currentSpot == (dataSize))
			resize((int)(dataSize*1.5));
		
		data[currentSpot++] = elem;
		actualSize+=1;
	}
	
	/**************************************************************
 	* Returns a random element from the array, then fills in the
 	* gap.
 	*
 	* @return A random element from the array.
 	* ************************************************************/
	T pop() {
		//If the size is 0, throw exception.
		if (dataSize == 0)
			throw std::out_of_range("Array is empty.");
			

		//If the size is 1, return the only element, then resize to 0.
		 else if (dataSize == 1) {
			T element = data[0];
			resize(dataSize-1);
			actualSize -= 1;	
			return element;
		
		//All other cases: get random element, swap with last element,
		//Then resize by 1, and return the element.
		} else {
			int index = rand() % dataSize;
			T element = data[index];
			std::swap(data[dataSize-1], data[index]);
			resize(dataSize-1);
			actualSize -= 1;
			return element;
		}
	}
	
private:
	/* This is the array that will hold the values. */
	T* data;

	/* Size of the array. Will change over course of program life. */
	int dataSize = 100;

	/* Actual number of elements in an array. */
	int actualSize;

	/* Current spot in the array. */
	int currentSpot;

	/**************************************************************
 	* Resize method. Called when the currentSpot variable is equal
 	* to the size variable. 
 	*
 	* Starts by declaring dynamic array of type T, called temp, 
 	* 	with size of size*1.5.
 	* Next, copies the contents of data into temp, so they aren't 
 	* 	lost.
 	* After, multiplies size by 1.5, then deletes the old data 
 	* 	array. We have to do this because data is a dynamically
 	* 	allocated array, which means the system won't 
 	* 	automatically free memory when it's done.
 	* Next, we recreate data array with the new size, then copies 
 	* 	the elements back in.
 	* Finally, sets data equal to temp.
 	* ************************************************************/
	void resize(int newSize) {

		//Creates temp array.
		T* temp = new T[newSize];

		//Copies elements over.
		//Can't just use size or newsize in loop; 
		//the 2 arrays differ in size,
		//so indexoutofbounds would definitely happen.
		if (dataSize < newSize)
			for(int i = 0; i < dataSize; i++)
				temp[i] = data[i];
		else
			for (int i = 0; i < newSize; i++)
				temp[i] = data[i];

		//Set size to newSize.
		dataSize = newSize;

		//Deletes data array.
		delete[] data;
		
		//Recreates data array with size.
		data = new T[dataSize];

		//Uses for loop to copy elements back to data.
		for(int i = 0; i < dataSize; i++) {
			data[i] = temp[i];
		}
		
		//Deletes temp now that we no longer need it.
		delete[] temp;
	
	}
};

#endif
