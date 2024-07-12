# 使用Vscode + Linux + LeetCode 刷题

#  ------ 环境配置 ------
  在Linux下安装node
  在VsCode下载插件LeetCode,配置LeetCode设置好node.js的路径和输出文件路径
  在VsCode中打开设置输入Preferences: Configure User Snippets,向这个json文件中加入如下
    
    "For LeetCode": {
        "prefix": "header",
        "body": [
			"#include <bits/stdc++.h>",
			"using namespace std;",
            "",
        ],
        "description": "For LeetCode"
    }
  
  上面的东西配置好之后在创建的cc/cpp文件中输入 header + Enter 就会自动在这个地方添加 上面的body.
  
  之后再设置相应的快捷键即可,如果题目为英文,设置当前用户的setting.json中的  "leetcode.useEndpointTranslation": true 显示题目为中文.
  
  本人具体的setting.json文件内如如下:
  
    "leetcode.nodePath": "/usr/local/lib/node/nodejs/bin/node",
    "leetcode.defaultLanguage": "cpp",
    "leetcode.endpoint": "leetcode-cn",
    "leetcode.filePath": {
        "default": {
            "folder": "",
            "filename": "${id}.${kebab-case-name}.${ext}"
        }
    },
    "cmake.showOptionsMovedNotification": false,
    "editor.defaultFormatter": "xaver.clang-format",
    "leetcode.useEndpointTranslation": true,
    "leetcode.workspaceFolder": "/home/qc/LeetCode",
    "C_Cpp.clang_format_fallbackStyle": "file",
    "editor.renderWhitespace": "all",
    "explorer.confirmDragAndDrop": false,
        "leetcode.editor.shortcuts": [
        "submit",
        "test",
        "solution",
        "description"
    ],
    "markdown.preview.lineHeight": 2,
    "markdown.preview.fontFamily": "'Fira Code'",
    "leetcode.hint.configWebviewMarkdown": false
  
   

