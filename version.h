#ifndef VERSION_H
#define VERSION_H

namespace AutoVersion{
	
	//Date Version Types
	static const char DATE[] = "22";
	static const char MONTH[] = "01";
	static const char YEAR[] = "2015";
	static const char UBUNTU_VERSION_STYLE[] =  "15.01";
	
	//Software Status
	static const char STATUS[] =  "Alpha";
	static const char STATUS_SHORT[] =  "a";
	
	//Standard Version Type
	static const long MAJOR  = 1;
	static const long MINOR  = 2;
	static const long BUILD  = 216;
	static const long REVISION  = 1176;
	
	//Miscellaneous Version Types
	static const long BUILDS_COUNT  = 254;
	#define RC_FILEVERSION 1,2,216,1176
	#define RC_FILEVERSION_STRING "1, 2, 216, 1176\0"
	static const char FULLVERSION_STRING [] = "1.2.216.1176";
	
	//These values are to keep track of your versioning state, don't modify them.
	static const long BUILD_HISTORY  = 16;
	

}
#endif //VERSION_H
