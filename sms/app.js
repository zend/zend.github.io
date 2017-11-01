var thread = $('.chat-thread')
var savedUrl = localStorage.getItem("url")
var url = saveUrl || "https://dh.eaxi.com/smsproxy"
thread.css({ 'min-height': $(window).height() })

log('系统消息', new Date(), '当前服务器地址为：' + url 
  + "<br>发送短信 SPURL=http://new.url.domain.com 修改。")

pollMessage()
setInterval(function() {
  pollMessage()
}, 10000)


function uploadMessage(sender, time, body) {
  if (body.substring(0, 6) == 'SPURL=') {
    url = body.substring(6)
    localStorage.setItem("url", url)
    log('系统消息', new Date(), 'Done. New URL='+url);
    return
  }
  $.post(url + '/index.php', {
    sender: sender, time: time, body: body
  }, function(res) {
    log(sender, time, body)
  }, 'JSON').fail(function() {
    log('error', new Date(), 'Can not upload message.')
  })
}

function pollMessage() {
  $.get(url + '/poll.php', function(data) {
    data = data.replace(/^\s+|\s+$/g, '')
    if (!data) return;
    var arr = data.split("\n");
    if (arr.length < 2) return;
    var to = arr[0]
    var body = arr[1]
    if (typeof SmsProxy !== 'undefined') SmsProxy.sendSms(to, body);
    log(to, new Date(), body, 'mine')
  }).fail(function() {
    log('error', new Date(), 'Network error')
  })
}

function log(s, t, b, w) {
  if (w == 'mine') {
    thread.append('<li class="meta">TO: '+s+'<br>' + (t?t:new Date()) + '</li>');
    thread.append('<li class="bubble mine"><span class="body">'+b+'</span></li>');
  } else {
    thread.append('<li class="meta">FROM: '+s+'<br>' + t + '</li>');
    thread.append('<li class="bubble their"><span class="body">'+b+'</span></li>');
  }
  setTimeout(function() {window.scrollBy(0, 800);}, 500)
}
