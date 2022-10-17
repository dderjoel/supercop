#include "consts.h"

const double alpha22[4] __attribute__ ((aligned (32)))
                        = {28334198897217871282176.0,
			   28334198897217871282176.0,
			   28334198897217871282176.0,
			   28334198897217871282176.0}; /* 2^22(2^52+2^51) */

const double alpha43[4] __attribute__ ((aligned (32))) = {
59421121885698253195157962752.0,
59421121885698253195157962752.0,
59421121885698253195157962752.0,
59421121885698253195157962752.0,
} ; /* 2^43(2^52+2^51) */

const double alpha64[4] __attribute__ ((aligned (32))) = {
124615124604835863084731911901282304.0,
124615124604835863084731911901282304.0,
124615124604835863084731911901282304.0,
124615124604835863084731911901282304.0,
} ; /* 2^64(2^52+2^51) */

const double alpha85[4] __attribute__ ((aligned (32))) = {
261336857795280739939871698507597986398208.0,
261336857795280739939871698507597986398208.0,
261336857795280739939871698507597986398208.0,
261336857795280739939871698507597986398208.0,
} ; /* 2^85(2^52+2^51) */

const double alpha106[4] __attribute__ ((aligned (32))) = {
548063113999088594326381812268606132370974703616.0,
548063113999088594326381812268606132370974703616.0,
548063113999088594326381812268606132370974703616.0,
548063113999088594326381812268606132370974703616.0,
} ; /* 2^106(2^52+2^51) */

const double alpha127[4] __attribute__ ((aligned (32))) = {
1149371655649416643768760270362731887714054341637701632.0,
1149371655649416643768760270362731887714054341637701632.0,
1149371655649416643768760270362731887714054341637701632.0,
1149371655649416643768760270362731887714054341637701632.0,
} ; /* 2^127(2^52+2^51) */

const double _2pm22[4] __attribute__ ((aligned (32)))
                        = {.0000002384185791015625,
                           .0000002384185791015625, 
                           .0000002384185791015625, 
                           .0000002384185791015625}; /* 2^-22 */
const double _2pm43[4] __attribute__ ((aligned (32)))
                        = {.0000000000001136868377216160297393798828125,
                           .0000000000001136868377216160297393798828125,
                           .0000000000001136868377216160297393798828125,
                           .0000000000001136868377216160297393798828125}; /* 2^-43 */
const double _2pm64[4] __attribute__ ((aligned (32)))
                        = {.0000000000000000000542101086242752217003726400434970855712890625,
                           .0000000000000000000542101086242752217003726400434970855712890625,
                           .0000000000000000000542101086242752217003726400434970855712890625,
                           .0000000000000000000542101086242752217003726400434970855712890625}; /* 2^-64 */
const double _2pm85[4] __attribute__ ((aligned (32)))
                        = {.0000000000000000000000000258493941422821148397315216271863391739316284656524658203125,
                           .0000000000000000000000000258493941422821148397315216271863391739316284656524658203125,
                           .0000000000000000000000000258493941422821148397315216271863391739316284656524658203125,
                           .0000000000000000000000000258493941422821148397315216271863391739316284656524658203125}; /* 2^-85 */
const double _2pm106[4]__attribute__ ((aligned (32)))
                        = {.0000000000000000000000000000000123259516440783094595582588325435348386438505485784844495356082916259765625,
                           .0000000000000000000000000000000123259516440783094595582588325435348386438505485784844495356082916259765625,
                           .0000000000000000000000000000000123259516440783094595582588325435348386438505485784844495356082916259765625,
                           .0000000000000000000000000000000123259516440783094595582588325435348386438505485784844495356082916259765625}; /* 2^-106 */
const double _2pm127[4]__attribute__ ((aligned (32)))
                        = {.0000000000000000000000000000000000000058774717541114375398436826861112283890933277838604376075437585313920862972736358642578125,
                           .0000000000000000000000000000000000000058774717541114375398436826861112283890933277838604376075437585313920862972736358642578125,
                           .0000000000000000000000000000000000000058774717541114375398436826861112283890933277838604376075437585313920862972736358642578125,
                           .0000000000000000000000000000000000000058774717541114375398436826861112283890933277838604376075437585313920862972736358642578125}; /* 2^-127 */

const double _2p22[4]__attribute__ ((aligned (32)))
                        = {4194304.,
                         4194304.,
                         4194304.,
                         4194304.};

const double _2p43[4]__attribute__ ((aligned (32)))
                        = {8796093022208.,
                         8796093022208.,
                         8796093022208.,
                         8796093022208.};

const double _2p64[4]__attribute__ ((aligned (32)))
                        = {18446744073709551616.,
                         18446744073709551616.,
                         18446744073709551616.,
                         18446744073709551616.};

const double _2p85[4]__attribute__ ((aligned (32)))
                        = {38685626227668133590597632.,
                         38685626227668133590597632.,
                         38685626227668133590597632.,
                         38685626227668133590597632.};

const double _2p106[4]__attribute__ ((aligned (32)))
                        = {81129638414606681695789005144064.,
                          81129638414606681695789005144064.,
                          81129638414606681695789005144064.,
                          81129638414606681695789005144064.};

const double _2p127[4]__attribute__ ((aligned (32)))
                        = {170141183460469231731687303715884105728.,
                          170141183460469231731687303715884105728.,
                          170141183460469231731687303715884105728.,
                          170141183460469231731687303715884105728.};

   const double _2[4]__attribute__ ((aligned (32)))
                           = {2.,
                         2.,
                         2.,
                         2.};

   const double _2p23[4]__attribute__ ((aligned (32)))
                           = {8388608,
                            8388608,
                            8388608,
                            8388608};

   const double _2p44m2p23[4]__attribute__ ((aligned (32)))
                           = {17592177655808.,
     17592177655808.,
     17592177655808.,
     17592177655808.};

   const double _2p65m2p44[4]__attribute__ ((aligned (32)))
                           = {
     36893470555233058816.,
     36893470555233058816.,
     36893470555233058816.,
     36893470555233058816.};

   const double _2p86m2p65[4]__attribute__ ((aligned (32)))
                           = {
     77371215561848119762092032.,
     77371215561848119762092032.,
     77371215561848119762092032.,
     77371215561848119762092032.};

   const double _2p107m2p86[4]__attribute__ ((aligned (32)))
                           = {
     162259199457960908055310829092864.,
     162259199457960908055310829092864.,
     162259199457960908055310829092864.,
     162259199457960908055310829092864.};

   const double _2p128m2p107[4]__attribute__ ((aligned (32)))
                           = {
     340282204661661634250011215853757923328.,
     340282204661661634250011215853757923328.,
     340282204661661634250011215853757923328.,
     340282204661661634250011215853757923328.};


    const double _2p43m1[4]__attribute__ ((aligned (32))) 
                = {
    8796093022207.,
    8796093022207.,
    8796093022207.,
    8796093022207.};

    const double _2p85m2p43[4]__attribute__ ((aligned (32))) 
                = {
    38685626227659337497575424.,
    38685626227659337497575424.,
    38685626227659337497575424.,
    38685626227659337497575424.};

    const double _2p127m2p85[4]__attribute__ ((aligned (32))) 
                = {
                  170141183460430546105459635582293508096.,
                  170141183460430546105459635582293508096.,
                  170141183460430546105459635582293508096.,
                  170141183460430546105459635582293508096.};




  const double _2p44m2[4]__attribute__ ((aligned (32))) 
                = {
                  17592186044414.,
                  17592186044414.,
                  17592186044414.,
                  17592186044414.};

    const double _2p86m2p44[4]__attribute__ ((aligned (32))) 
                = {
    77371252455318674995150848.,
    77371252455318674995150848.,
    77371252455318674995150848.,
    77371252455318674995150848.};

    const double _2p128m2p86[4]__attribute__ ((aligned (32))) 
                = {
    340282366920861092210919271164587016192.,
    340282366920861092210919271164587016192.,
    340282366920861092210919271164587016192.,
    340282366920861092210919271164587016192.};



const double _1111[4]__attribute__ ((aligned (32)))
                        = {1.,
                        1.,
                        1.,
                        1.};

const double _two[4]__attribute__ ((aligned (32)))
                        = {2.,
                        2.,
                        2.,
                        2.};

const double stepconsts[4]__attribute__ ((aligned (32)))
                        = {-114., 
                                57., 
                                66., 
                               418.};

const double hadstepconsts[4]__attribute__ ((aligned (32)))
                        = {833., 
                               -2499., 
                               -1617.,
                                -561.};

const double minusz[4]__attribute__ ((aligned (32)))
                        = {1, 1, -1, 1};
const double newabcd[4]__attribute__ ((aligned (32)))
                        = {-114,57,-66,418};
const double newABCD[4]__attribute__ ((aligned (32)))
                        = {833,-561,1617,-2499};


const unsigned long long mask63 __attribute__ ((aligned (32)))
                        = 0x7fffffffffffffff;

const unsigned char _one[16]__attribute__ ((aligned (32)))
                        = {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
