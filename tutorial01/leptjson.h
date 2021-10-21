#ifndef LEPTJSON_H__
#define LEPTJSON_H__

typedef enum { LEPT_NULL, LEPT_FALSE, LEPT_TRUE, LEPT_NUMBER, LEPT_STRING, LEPT_ARRAY, LEPT_OBJECT } lept_type;//声明一个枚举类型

typedef struct {
    lept_type type;
}lept_value;

enum {
    LEPT_PARSE_OK = 0,
    LEPT_PARSE_EXPECT_VALUE,//如果json只有空白，返回这个
    LEPT_PARSE_INVALID_VALUE,//如果一个值之后，在空白之后还有其他字符，返回这个
    LEPT_PARSE_ROOT_NOT_SINGULAR//如果不是这三种值，返回这个
};

//解析json
int lept_parse(lept_value* v, const char* json);

//访问结果，获取类型
lept_type lept_get_type(const lept_value* v);

#endif /* LEPTJSON_H__ */
