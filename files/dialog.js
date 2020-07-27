// When the user scrolls down 20px from the top of the document, show the button
window.onscroll = function() {scrollFunction()};

function scrollFunction() {
    if ((window.innerHeight + window.scrollY) >= document.body.scrollHeight) {
        document.getElementById("tobottom").style.display = "none";
    } else {
        document.getElementById("tobottom").style.display = "block";
    }
}

function toBottom(){
    window.scrollTo(0,document.body.scrollHeight);
}

function toTop(){
    window.scrollTo(0,0);
}

function append(){
	var val = "text"
	var txt = document.getElementById(val).value;
	if (txt.length > 0) {
		var d = new Date();
		document.getElementById("content").innerHTML += '<p class="triangle-right right">' + txt + '<span class="byline">' + d.getHours() + ':' + d.getMinutes() + '</span></p>';
		document.getElementById(val).value = "";
	}
}