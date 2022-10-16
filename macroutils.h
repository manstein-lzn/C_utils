#define str_(x) #x
#define MCR_STR(x) str_(x)

#define MCR_CONCAT(A,B) A##B


//manual setting
// #define STRCT INTVECTOR                               //type name
// #define STRCT_H intvector.h                           //type header file name
// #define TESTVECTOR MCR_CONCAT(STRCT, _STRCTVECTOR)    //unique vector name to use outscope define

//auto setting
// #include MCR_STR(STRCT_H)