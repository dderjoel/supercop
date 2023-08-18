- libsecp256k1-ots                     using libsecp256k1's `asm_impl`
- libsecp256k1-c-ots                   using libsecp256k1's `c`-fallback (including optimization, #810)

- libsecp256k1-ots-champ-bcc           using libsecp256k1 with the best optimized CryptOpt Solution based off their C to LLVM
- libsecp256k1-ots-champ-cryptopt      using libsecp256k1 with the best optimized CryptOpt solution based off Fiat-C
- libsecp256k1-ots-cryptopt-dettman         using libsecp256k1's `asm_impl` with cryptopt-optimized dettman  for mul
- libsecp256k1-ots-cryptopt-bcc             using libsecp256k1's `asm_impl` with cryptopt-optimized fe based on their llvm

(Moved to ~-skip for now)
- libsecp256k1-ots-c-dettman           using libsecp256k1              with Fiat Generated C-Dettman (mul and sq)
- libsecp256k1-c-52-ots                using libsecp256k1's `c`-fallback (before optimization, #810, using 52-shifts)
