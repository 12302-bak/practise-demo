#include "proxy.h"

void printProxies(CFDictionaryRef proxies) {
    if (proxies == NULL) {
        printf("No proxies available.\n");
        return;
    }

    // 获取字典中的键数量
    CFIndex count = CFDictionaryGetCount(proxies);
    if (count == 0) {
        printf("No proxies available.\n");
        return;
    }

    // 分配内存来存储键和值
    const void **keys = (const void **)malloc(sizeof(void *) * count);
    const void **values = (const void **)malloc(sizeof(void *) * count);

    // 获取字典中的所有键和值
    CFDictionaryGetKeysAndValues(proxies, keys, values);

    for (CFIndex i = 0; i < count; i++) {
        CFStringRef key = (CFStringRef)keys[i];
        CFTypeRef value = values[i];

        // 打印键值对
        char keyBuf[256];

        if (CFStringGetCString(key, keyBuf, sizeof(keyBuf), kCFStringEncodingUTF8)) {
            printf("%s: ", keyBuf);
        } else {
            printf("Key (non-string): ");
        }

        // 打印值
        if (CFGetTypeID(value) == CFStringGetTypeID()) {
            // 处理字符串类型
            char valueBuf[256];
            if (CFStringGetCString((CFStringRef)value, valueBuf, sizeof(valueBuf), kCFStringEncodingUTF8)) {
                printf("%s\n", valueBuf);
            } else {
                printf("(unable to convert string value)\n");
            }
        } else if (CFGetTypeID(value) == CFNumberGetTypeID()) {
            // 处理数字类型
            int intValue;
            if (CFNumberGetValue((CFNumberRef)value, kCFNumberIntType, &intValue)) {
                printf("%d\n", intValue);
            } else {
                printf("(unable to convert number value)\n");
            }
        } else if (CFGetTypeID(value) == CFBooleanGetTypeID()) {
            // 处理布尔类型
            Boolean boolValue = CFBooleanGetValue((CFBooleanRef)value);
            printf(boolValue ? "true\n" : "false\n");
        } else if (CFGetTypeID(value) == CFDataGetTypeID()) {
            // 处理数据类型
            CFDataRef data = (CFDataRef)value;
            const UInt8 *bytes = CFDataGetBytePtr(data);
            CFIndex length = CFDataGetLength(data);
            printf("Data: ");
            for (CFIndex j = 0; j < length; j++) {
                printf("%02x ", bytes[j]);
            }
            printf("\n");
        } else {
            // 处理其他类型
            printf("(unknown type)\n");
        }
    }

    // 释放分配的内存
    free(keys);
    free(values);
}