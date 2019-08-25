# config_parser
ini配置文件解析器

#使用方法
CConfigParser *pConParser = new CConfigParser();
bool res = pConParser->Parser("cfg.ini");
if (res) {
    //获取配置
    string ip = pConParser->GetConfig("default", "IP");
    string port = pConParser->GetDefConfig("default", "PORT", "8888");

    //检测是否有某个section
    if (pConParser->HasSection("default")) {
        //xxxxx
    }

    //获取所有section
    vector<string> vecSections;
    pConParser->GetSections(vecSections));

    //获取section所有key
    vector<string> vecKeys;
    pConParser->GetSections("default",vecKeys));
}
