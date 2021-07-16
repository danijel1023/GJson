#pragma once

enum class Json_Type { Number, String, Bool, Null, Object, Array };

struct Json_Node {
    Json_Type m_Type;
    void* m_Data = nullptr;
};
