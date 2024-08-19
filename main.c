#include <stdio.h>
#include "cJSON.h"
#include "proxy.h"

int proxies_manipulate(){
    // 创建 SCDynamicStore
    SCDynamicStoreRef store = SCDynamicStoreCreate(NULL, CFSTR("ProxyPrinter"), NULL, NULL);
    if (store == NULL) {
        fprintf(stderr, "Failed to create SCDynamicStore.\n");
        return 1;
    }

    // 获取代理设置
    CFDictionaryRef proxies = SCDynamicStoreCopyProxies(store);
    if (proxies == NULL) {
        fprintf(stderr, "Failed to get proxies.\n");
        CFRelease(store);
        return 1;
    }

    // 打印代理设置
    printProxies(proxies);

    // 释放资源
    CFRelease(proxies);
    CFRelease(store);
    return 0;
}


int cJson_manipulate(){
    char* json_string = "{""\"name\": \"John\",""\"age\": 30,""\"is_student\": false,""\"scores\": [85, 90, 78],""\"address\": {""\"city\": \"New York\",""\"zipcode\": \"10001\"""}""}";

    // 解析 JSON 字符串
    cJSON *json = cJSON_Parse(json_string);
    if (json == NULL) {
        printf("Error parsing JSON!\n");
        return 1;
    }

    // 从 JSON 对象中提取数据
    cJSON *name = cJSON_GetObjectItem(json, "name");
    cJSON *age = cJSON_GetObjectItem(json, "age");
    cJSON *is_student = cJSON_GetObjectItem(json, "is_student");
    cJSON *scores = cJSON_GetObjectItem(json, "scores");
    cJSON *address = cJSON_GetObjectItem(json, "address");

    // 打印提取的数据if (cJSON_IsString(name) && name->valuestring != NULL) {
    printf("Name: %s\n", name->valuestring);
    printf("Age: %d\n", age->valueint);
    printf("Is Student: %s\n", cJSON_IsTrue(is_student) ? "true" : "false");

    int score_count = cJSON_GetArraySize(scores);
    printf("Scores: ");
    for (int i = 0; i < score_count; i++) {
        cJSON *score = cJSON_GetArrayItem(scores, i);
        if (cJSON_IsNumber(score)) {
            printf("%d ", score->valueint);
        }
    }
    printf("\n");

    cJSON *city = cJSON_GetObjectItem(address, "city");
    cJSON *zipcode = cJSON_GetObjectItem(address, "zipcode");
    printf("City: %s\n", city->valuestring);
    printf("Zipcode: %s\n", zipcode->valuestring);

    //delete cjson
    cJSON_Delete(json);

    return 0;
}

int main() {

    cJson_manipulate();
    printf("=========================\n\n");

    proxies_manipulate();
    printf("=========================\n\n");

    printf("hello world\n");
    return 0;
}

