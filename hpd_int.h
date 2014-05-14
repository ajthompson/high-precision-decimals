/**
 * high-precision-decimal library
 *
 * @author Alec Thompson - ajthompson042@gmail.com
 *
 * hpd_int -  provides an integer based fixed-point data type for high 
 * precision decimal without the accuracy issues inherent in floating point 
 * values' binary handling of numbers. This also avoids the inconsistent
 * precision of floating point values, where numbers close to zero will have a
 * much higher resolution than those far from zero
 *
 * hpd_int's range varies by compiler, and is dependent on the sizeof(int).
 *
 * On 16-bit systems such as Arduino Uno's, Mega's and others where int values
 * are two bytes, the range of an hpd_int is -32768.9999 to 32767.9999, with a
 * resolution of 0.0001.
 *
 * On 32- and 64-bit systems such as most modern processors and the 32-bit 
 * Arduino Due, where the int values are 4 bytes, the range of an hpd_int is
 * -214783648.999999999 to 214783647.999999999 with a resolution of 1 * 10 ^ -9
 *
 * This consistent precision comes at the cost of wasted space and more limited
 * range, as less than 1/6th of the respresentable range for 16-bit integers is
 * used in the representation of values to the right of the decimal place, and 
 * less than 1/4th of the range is used for 32-bit integers.
 */

#include <string>
using std::string;

class hpd_int {
public:
    // constructors
    hpd_int(int, unsigned int); // construct from the 
    hpd_int(float);
    hpd_int(string);
    // operator overloads
    // getters and setters
    int getLeft();
    void setLeft(int);
    unsigned int getRight();
    void getRight(unsigned int);
private:
    int left; // stores values to the left of the decimal place
    unsigned int right; // stores values to the right of the decimal place
}
