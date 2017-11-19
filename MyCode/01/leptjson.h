// 项目名称_目录_文件名_H__
#ifndef LEPTJSON_H__
#define LEPTJSON_H__

// JSON数据类型
typedef enum { LEPT_NULL,
               LEPT_FALSE,
               LEPT_TRUE,
               LEPT_NUMBER,
               LEPT_STRING,
               LEPT_ARRAY,
               LEPT_OBJECT
            } lept_type;

// JSON数据值
typedef struct {
    lept_type type;
} lept_value;

// 函数调用返回错误码
enum
{
    LEPT_PARSE_OK = 0,
    LEPT_PARSE_EXPECT_VALUE,        // JSON只有空白
    LEPT_PARSE_INVALID_VALUE,       // 非正确字面值
    LEPT_PARSE_ROOT_NOT_SINGULAR        // 空白之后还有其他字符
};

// 解析JSON函数
int lept_parse(lept_value* v, const char* json);

// 访问结果函数
lept_type lept_get_type(const lept_value* v);

#endif