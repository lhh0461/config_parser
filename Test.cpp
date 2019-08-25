#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <assert.h>

#include "ConfigParser.h"

using namespace XEngine;

int Test()
{
    CConfigParser *pConParser = new CConfigParser();
    bool res = pConParser->Parser("cfg.ini");
    if (res == true) {
        vector<string> vec;
        pConParser->GetSections(vec);
        for (auto it : vec) {
            cout << "section=" << it << endl;
        }

        vector<string> vecKeys;
        pConParser->GetKeys("default", vecKeys);
        for (auto it : vecKeys) {
            cout << "key=" << it << endl;
        }

        assert(pConParser->HasSection("default"));
        assert(pConParser->HasSection("section1"));
        assert(!pConParser->HasSection("NOT_EXIST_SECTION"));

        assert(pConParser->GetConfig("default", "IP") == "127.0.0.1");
        assert(pConParser->GetDefConfig("default", "IP", "111.111.111.111") == "127.0.0.1");

        assert(pConParser->GetConfig("default", "NOT_EXIST_KEY").empty());
        assert(pConParser->GetDefConfig("default", "NOT_EXIST_KEY", "999") == "999");

        assert(pConParser->GetConfig("NOT_EXIST_SECTION", "IP").empty());
        assert(pConParser->GetDefConfig("NOT_EXIST_SECTION", "IP", "127.0.0.1") == "127.0.0.1");
    } else {
        vector<string> vec;
        pConParser->GetSections(vec);
        assert(vec.size() == 0);

        vector<string> vecKeys;
        pConParser->GetKeys("default", vecKeys);
        assert(vecKeys.size() == 0);
    }
}

int main()
{
    Test();
}
