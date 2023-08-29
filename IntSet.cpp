// FILE: IntSet.cpp - header file for IntSet class
//       Implementation file for the IntStore class
//       (See IntSet.h for documentation.)
// INVARIANT for the IntSet class:
// (1) Distinct int values of the IntSet are stored in a 1-D,
//     compile-time array whose size is IntSet::MAX_SIZE;
//     the member variable data references the array.
// (2) The distinct int value with earliest membership is stored
//     in data[0], the distinct int value with the 2nd-earliest
//     membership is stored in data[1], and so on.
//     Note: No "prior membership" information is tracked; i.e.,
//           if an int value that was previously a member (but its
//           earlier membership ended due to removal) becomes a
//           member again, the timing of its membership (relative
//           to other existing members) is the same as if that int
//           value was never a member before.
//     Note: Re-introduction of an int value that is already an
//           existing member (such as through the add operation)
//           has no effect on the "membership timing" of that int
//           value.
// (4) The # of distinct int values the IntSet currently contains
//     is stored in the member variable used.
// (5) Except when the IntSet is empty (used == 0), ALL elements
//     of data from data[0] until data[used - 1] contain relevant
//     distinct int values; i.e., all relevant distinct int values
//     appear together (no "holes" among them) starting from the
//     beginning of the data array.
// (6) We DON'T care what is stored in any of the array elements
//     from data[used] through data[IntSet::MAX_SIZE - 1].
//     Note: This applies also when the IntSet is empry (used == 0)
//           in which case we DON'T care what is stored in any of
//           the data array elements.
//     Note: A distinct int value in the IntSet can be any of the
//           values an int can represent (from the most negative
//           through 0 to the most positive), so there is no
//           particular int value that can be used to indicate an
//           irrelevant value. But there's no need for such an
//           "indicator value" since all relevant distinct int
//           values appear together starting from the beginning of
//           the data array and used (if properly initialized and
//           maintained) should tell which elements of the data
//           array are actually relevant.

#include "IntSet.h"
#include <iostream>
#include <cassert>
using namespace std;

//Constructor
IntSet::IntSet()
{
    used = 0;
    set[MAX_SIZE] = { 0 };
}

//Number of elements
int IntSet::size() const
{
   return used;
   //Returns the number of 'spaces' that are used in the 
   //IntSet array
}

//Is the IntSet empty? Yes or No
bool IntSet::isEmpty() const
{
   return used == 0;
   //Returns true if used = 0 (is empty) 
   //and false for used != 0 (is not empty)
}

//Does this IntSet contain the goal value?
bool IntSet::contains(int anInt) const
{
    if (isEmpty() == false)
    {
        for (int i = 0; i < MAX_SIZE; i++) {
            if (set[i] == anInt)
            {
                return true;
            }
        }
   }
    return false;
}

//Is the set a subset? This includes empty sets! (Does not need to be in order)
bool IntSet::isSubsetOf(const IntSet& otherIntSet) const
{
    //Empty sets are always subsets
    if (otherIntSet.isEmpty == true)
    {
        return true;
    }

    //Loop through the IntSet 
    for (int i = 0; i < MAX_SIZE; i++)
    {
        originalElement = IntSet[i];

        //Loop through the otherIntSet
        for (int j = 0; j < MAX_SIZE; j++)
        {
            if (originalElement == otherIntSet[j])
                return true;
        }
    }
    //If it exits both loops, must return false
   return false; 
}

void IntSet::DumpData(ostream& out) const
{  // already implemented ... DON'T change anything
   if (used > 0)
   {
      out << data[0];
      for (int i = 1; i < used; ++i)
         out << "  " << data[i];
   }
}

IntSet IntSet::unionWith(const IntSet& otherIntSet) const
{
   cout << "unionWith() is not implemented yet..." << endl;
   return IntSet(); // dummy IntSet object returned
}

IntSet IntSet::intersect(const IntSet& otherIntSet) const
{
   cout << "intersect() is not implemented yet..." << endl;
   return IntSet(); // dummy IntSet object returned
}

IntSet IntSet::subtract(const IntSet& otherIntSet) const
{
   cout << "subtract() is not implemented yet..." << endl;
   return IntSet(); // dummy IntSet object returned
}

void IntSet::reset()
{
    //Delete all elements and set used to 0
    used = 0;
}

//This can be more effective if you switch the initial check
bool IntSet::add(int anInt)
{
    //Check to see if there is room left in the array
    if (used >= MAX_SIZE)
    {
        //If there is NOT any room, cout and return false
        cout << "There is no more room to add an integer!";
        return false;
    }
    else
    {
        if (contains(anInt))
        {
            //If the array already contains the integer, do NOT add and return
            //false
            return false;
        }
        else
        {
            //If the array does NOT contain the integer, add to array and increment used
            data[used] = anInt;
            used++;
            return true;
        }
    }

   return false;
}

bool IntSet::remove(int anInt)
{
    //Check to see if there is anything to remove
    if (used <= 0)
    {
        cout << "There is nothing to remove";
        return false;
    }
    //Check to see if the array contains the integer
    if (contains(anInt))
    {
        //Remove the integer
    }
    //If the array does not contain the integer, return false 
    //(this is because nothing has changed)
   return false;
}

//Returns true if the sets are equal 
bool equal(const IntSet& is1, const IntSet& is2)
{
   cout << "equal() is not implemented yet..." << endl;
   return false; // dummy value returned
}
