// JSBridge不是一种框架，是一种形式，一种思想


// window.JSBridge = {
//     // 调用原生
//     invoke: function(bridgeName, data) {
//         // 通过原生提供的对象，调用原生功能
//         nativeBridge.postMessage({
//             bridgeName: bridgeName,
//             data: data || {}
//         })
//     },
//     // 接收原生消息
//     receiveMessage: function(msg) {
//         //接收数据
//         var bridgeName = msg.bridgeName;
//         var data = msg.data || {};
//         // 后续逻辑
//     }
// }

// 匿名函数执行
(function() {
    // 标记
    var id = 0;
    // 回调函数仓库
    var callbacks = {};
    window.JSBridge = {
        // 调用原生
        invoke: function(bridgeName, callback, data) {
            //唯一id
            var thisId = id++;
            // 保存回调函数
            callbacks[thisId] = callback;
            // 通过原生提供的对象，调用原生功能
            nativeBridge.postMessage({
                bridgeName: bridgeName,
                data: data || {},
                callback: callback
            })
        },
        // 接收原生消息
        receiveMessage: function(msg) {
            //接收数据
            var bridgeName = msg.bridgeName;
            var data = msg.data || {};
            var callbackId = msg.callbackId;
            // 后续逻辑
            if (callbackId) {
                if (callbacks[callbackId]) {
                    callbacks[callbackId](data);
                }
            }
        }
    }
})()