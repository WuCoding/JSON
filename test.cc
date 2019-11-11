#include "stdio.h"
#include <iostream>
#include <string>
#include <json/json.h>
#include <fstream>

using namespace std;

string createJSON()
{
	Json::Value req;
	req["Result"] = 1;
	req["ResultMessage"] = "200";
	
	Json::Value object1;
	object1["cpuRatio"] = "4.04";
	object1["serverIp"] = "42.159.116.104";
	object1["conNum"] = "1";
	object1["websocketPort"] = "0";
	object1["mqttPort"] = "8883";
	object1["TS"] = "1504665880572";
	
	Json::Value object2;
	object2["cpuRatio"] = "2.04";
	object2["serverIp"] = "42.159.122.251";
	object2["conNum"] = "2";
	object2["websocketPort"] = "0";
	object2["mqttPort"] = "8883";
	object2["TS"] = "1504665896981";
	Json::Value jarray;
	jarray.append(object1);
	jarray.append(object2);
	
	req["ResultValue"] = jarray;
	Json::FastWriter writer;
	string jsonstr = writer.write(req);
	printf("%s\n", jsonstr.c_str());

	Json::StyledWriter swriter;
	jsonstr=swriter.write(req);
	printf("%s\n",jsonstr.c_str());


	return jsonstr;
}
int main()
{
	string jsonstr;
	jsonstr=createJSON();
	cout<<jsonstr<<endl;

	fstream out;
	out.open("result.json",ios::out);
	out<<jsonstr<<jsonstr;
	out.close();
}
