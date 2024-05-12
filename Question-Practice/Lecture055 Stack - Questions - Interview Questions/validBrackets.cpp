

bool isValidParenthesis(string expression) {
    stack<char> s;
    for (int i = 0; i < expression.length(); i++) {
        char ch = expression[i];

        // if opening bracket, stack push
        // if close bracket, stacktop check and pop

        if (ch == '(' || ch == '{' || ch == '[') {
            s.push(ch);
        } else {
            // for closing bracket
            if (!s.empty()) {
                char top = s.top();
                if ((ch == ')' && top == '(') || (ch == '}' && top == '{') ||
                    (ch == ']' && top == '[')) {
                    s.pop();
                } else {
                    return false;
                }
            } else {
                return false;
            }
        }
    }

    if (s.empty())
        return true;
    else
        return false;
}

/******************************Rajesh********************************************/

// bool isValidParenthesis(string s) {
//   stack<char> st;
//   for (int i = 0; i < s.size(); i++) {
//     if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
//       st.push(s[i]);
//     } else if (s[i] == ')') {
//       if (!st.empty() && st.top() == '(') {
//         st.pop();
//       } else {
//         return false; // Mismatched closing bracket
//       }
//     } else if (s[i] == ']') {
//       if (!st.empty() && st.top() == '[') {
//         st.pop();
//       } else {
//         return false; // Mismatched closing bracket
//       }
//     } else if (s[i] == '}') {
//       if (!st.empty() && st.top() == '{') {
//         st.pop();
//       } else {
//         return false; // Mismatched closing bracket
//       }
//     }
//   }
//   return st.empty();
// }