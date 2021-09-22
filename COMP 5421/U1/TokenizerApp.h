#ifndef TOKENIZERAPP_H_
#define TOKENIZERAPP_H_

#include "TList.h"

class TokenizerApp {
private:
    TList tokenList{};
public:
    void loadTokenList(const char* filename);

    TokenizerApp(const char* filename);

    void print(ostream& sout) const;
};

#endif
