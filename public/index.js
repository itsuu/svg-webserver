// Put all onload AJAX calls here, and event listeners
$(document).ready(function() {
    // On page-load AJAX Example
    var retrievedObjs = [];
    var obj;
    $.ajax({
        type: 'get',            //Request type
        dataType: 'JSON',       //Data type - we will use JSON for almost everything 
        url: '/addToWebsite',   //The server endpoint we are connecting to
        success: function (data) {
            /*  Do something with returned object
                Note that what we get is an object, not a string, 
                so we do not need to parse it on the server.
                JavaScript really does handle JSONs seamlessly
                */
            //$("#log-table").append("<tr>" + "<td>My First Video</td>" + "<td>6/11/2015</td>" + "<td>www.pluralsight.com</td>" + "</tr>");

            //$('#blah').html("On page load, received string '"+data.foo+"' from server");
            //We write the object to the console to show that the request was successful
            retrievedObjs = data;
            buildTable(retrievedObjs);
            buildDropBox(retrievedObjs);
            console.log(retrievedObjs);
        },
        fail: function(error) {
            // Non-200 return, do something with error
            //$('#blah').html("On page load, received error from server");
            console.log(error); 
        }
    });


    var checkButton = document.getElementById("upload-button");
    //checkButton.addEventListener("click", openFile(), false);
    document.getElementById("upload-button").onclick = function () {
        //openFile(submit());
        document.getElementById('fileInput').click();
        $('#fileInput').on('change', function() {
            document.getElementById('submit-button').click();

            $.ajax({
            type: 'get',            //Request type
            dataType: 'JSON',       //Data type - we will use JSON for almost everything 
            url: '/alertMessage',   //The server endpoint we are connecting to
            success: function (data) {
                var message = data;
                console.log(message.uploadedFileName +" " +message.returnMessage);
                alert(message.uploadedFileName +" " +message.returnMessage);
                console.log(data);
            },
            fail: function(error) {
                console.log(error); 
            }
        });
        });
    };
    
    $("select.svgs").change(function() {
        var selectedSVG = $(this).children("option:selected").val();
        //alert("You have selected the country - " + selectedSVG);
        //sendValue();

        //selectedSVG = $(this).children("option:selected").val();
        var svgString = {"fileName": selectedSVG};
        var s = JSON.stringify(svgString);
        console.log("s: "+s);
        $.ajax({
        type: 'get',           //Request type
        dataType: 'text',       //Data type - we will use JSON for almost everything 
        url: '/value',          //The server endpoint we are connecting to
        contentType: 'application/json',
        data: /*{name: JSON.stringify(svgString)}*/svgString,
        success: function (data) {
            //alert('Successfully connected to the server');
            console.log('Successfully connected to the server');
            var parsedData = JSON.parse(data);
            console.log(parsedData);

            buildViewPanel(parsedData);
        },
        fail: function(error) {
            //alert('Failure to connect to the server');
            console.log('Failure to connect to the server'); 
        }
    });
    });


    //Example ajax call
    $.ajax({
        type: 'get',            //Request type
        dataType: 'text',       //Data type - we will use JSON for almost everything 
        url: '/someendpoint',   //The server endpoint we are connecting to
        success: function (data) {
            /*  Do something with returned object
                Note that what we get is an object, not a string, 
                so we do not need to parse it on the server.
                JavaScript really does handle JSONs seamlessly
                */
                //$('#blah').html("On page load, received string '"+data.foo+"' from server");
            //We write the object to the console to show that the request was successful
            console.log(data);
        },
        fail: function(error) {
            // Non-200 return, do something with error
            //$('#blah').html("On page load, received error from server");
            console.log(error); 
        }
    });
    

    // Event listener form example , we can use this instead explicitly listening for events
    // No redirects if possible
    $('#someform').submit(function(e){
        $('#blah').html("Form has data: "+$('#entryBox').val());
        e.preventDefault();
        //Pass data to the Ajax call, so it gets passed to the server
        $.ajax({
            //Create an object for connecting to another waypoint
        });
    });
});


    /*
    var checkButton = document.getElementById("upload-Button");
    //checkButton.addEventListener("click", openFile(), false);
    
    if(checkButton) {
        checkButton.addEventListener("click", openFile(), false);
                console.log("FUCK");

    }
    else
    {
        console.log("FUCK");
    }
    */
    //document.getElementById('upload-Button').onclick = openFile();


    function buildTable(data) {

        var table = document.getElementById('log-body');
        var row;
    //<td><img src="H.gif" alt="" border=3 height=100 width=100></img></td>
    //<!-- a href="rects.svg">rects.svg</a -->
    for(var i = 0; i < data.length; i++) {
        row = ("<tr>" +
            "<td><a href="+data[i].fileName+" download> <img style=\"display:block;\" width=\"100%\" height=\"auto\" src="+data[i].fileName+" ></img></a></td>" +
            "<td><a href="+data[i].fileName+" download>"+data[i].fileName+"</a></td>" +
            "<td>"+data[i].fileSize+"</td>" +
            "<td>"+data[i].numRect+"</td>" +
            "<td>"+data[i].numCirc+"</td>" +
            "<td>"+data[i].numPaths+"</td>" +
            "<td>"+data[i].numGroups+"</td>" +
            "</tr>");
        table.innerHTML += row;
    }

    if(data.length === 0) {
        row = ("<tr>" +
            "<td>No Files</td>" +
            "<td>N/A</td>" +
            "<td>N/A</td>" +
            "<td>N/A</td>" +
            "<td>N/A</td>" +
            "<td>N/A</td>" +
            "<td>N/A</td>" +
            "</tr>");
        table.innerHTML += row;
    }
}

function buildDropBox(data) {

    var dropBox = document.getElementById('svg-images');
    var option;
    //<td><img src="H.gif" alt="" border=3 height=100 width=100></img></td>
    //<!-- a href="rects.svg">rects.svg</a -->
    for(var i = 0; i < data.length; i++) {
        option = ("<option value=\""+data[i].fileName+"\">"+data[i].fileName+"</option>");
        dropBox.innerHTML += option;
    }

    if(data.length === 0) {
        option = ("<option value=\"No Files\">No Files</option>");
        dropBox.innerHTML += option;
    }
}

function sendValue() {
    selectedSVG = $(this).children("option:selected").val();

    $.ajax({
        type: 'post',            //Request type
        dataType: 'JSON',       //Data type - we will use JSON for almost everything 
        url: '/value',   //The server endpoint we are connecting to
        data:{svgName: selectedSVG},
        success: function (data) {
            console.log(data);
        },
        fail: function(error) {
            console.log(error); 
        }
    });
}

function buildViewPanel(data) {
    var fileName = data[0].fileName;
    var title = data[1].svgTitle;
    var desc = data[1].svgDesc;
    var r = data[2];
    var c = data[3];
    var p = data[4];
    var g = data[5];

    //console.log("name: "+title);
    //console.log("r: "+data.length);
    //console.log("inside c: "+c.length);

    //console.log(r[0].x);
    var table1 = document.getElementById('pic');
    var pic = "<img style=\"display:block;\" width=\"800px\" height=\"auto\" class=\"center\" src="+fileName+" ></img>";
    table1.innerHTML = pic;

    var tableTitle = document.getElementById('title');
    var tableDesc = document.getElementById('desc');

    var titleHTML = "<td>"+title+"</td>";
    var descHTML = "<td>"+desc+"</td>";
    tableTitle.innerHTML = titleHTML;
    tableDesc.innerHTML = descHTML;

    var components = document.getElementById('c-body');
    components.innerHTML = '';
    
    for(var i in r) {
        var x = +i+ +1;
        var newR = "<tr>" +
        "<td>Rectangle "+x+"</td>" +
        "<td><textarea id=\"tr"+i+"\" rows=\"3\" cols=\"25\" text-align=\"center\" vertical-align=\"middle\">Upper left corner:[x="+r[i].x+r[i].units+", y="+r[i].y+r[i].units+", Width:"+r[i].w+r[i].units+", Height:"+r[i].h+r[i].units+"]</textarea></td>";
        if(r[i].numAttr > 0) {
            newR = newR + "<td id=\"r"+i+"\">"+r[i].numAttr+"<button type=\"button\" class=\"show\" onClick=\"showAttr(\'"+fileName+"\', "+i+", \'rect\', \'r"+i+"\')\" >Show</button></td>" +
            "<tr>";
        }
        else {
            newR = newR + "<td id=\"r"+i+"\">"+r[i].numAttr+"</td>" +
            "<tr>";
        }
        components.innerHTML += newR;
    }

    for(var i in c) {
        var x = +i+ +1;
        var newC = "<tr>" +
        "<td>Circle "+x+"</td>" +
        "<td><textarea id=\"tc"+i+"\" rows=\"3\" cols=\"25\" text-align=\"center\" vertical-align=\"middle\">Centre:[x="+c[i].cx+c[i].units+", y="+c[i].cy+c[i].units+", radius="+c[i].r+c[i].units+"]</textarea></td>";
        if(c[i].numAttr > 0) {
            newC = newC + "<td id=\"c"+i+"\">"+c[i].numAttr+"<button type=\"button\" class=\"show\" onClick=\"showAttr(\'"+fileName+"\', "+i+", \'circle\', \'c"+i+"\')\" >Show</button></td>" +
            "<tr>";
        }
        else {
            newC = newC + "<td id=\"c"+i+"\">"+c[i].numAttr+"</td>" +
            "<tr>";
        }
        components.innerHTML += newC;
    }

    for(var i in p) {
        var x = +i+ +1;
        var newP = "<tr>" +
        "<td>Path "+x+"</td>" +
        "<td><textarea id=\"tp"+i+"\"c rows=\"3\" cols=\"25\" text-align=\"center\" vertical-align=\"middle\">[path data="+p[i].d+"]</textarea></td>";
        if(p[i].numAttr > 0) {
            newP = newP + "<td id=\"p"+i+"\">"+p[i].numAttr+"<button type=\"button\" class=\"show\" onClick=\"showAttr(\'"+fileName+"\', "+i+", \'path\', \'p"+i+"\')\" >Show</button></td>" +
            "<tr>";
        }
        else {
            newP = newP + "<td id=\"p"+i+"\">"+p[i].numAttr+"</td>" +
            "<tr>";
        }
        components.innerHTML += newP;
    }

    for(var i in g) {
        var x = +i+ +1;
        var newG = "<tr>" +
        "<td>Group "+x+"</td>" +
        "<td><textarea id=\"tg"+i+"\" rows=\"3\" cols=\"25\" text-align=\"center\" vertical-align=\"middle\">["+g[i].children+" child elements]</textarea></td>";
        if(g[i].numAttr > 0) {
            newG = newG + "<td id=\"g"+i+"\">"+g[i].numAttr+"<button type=\"button\" class=\"show\" onClick=\"showAttr(\'"+fileName+"\', "+i+", \'group\', \'g"+i+"\')\" >Show</button></td>" +
            "<tr>";
        }
        else {
            newG = newG + "<td id=\"g"+i+"\">"+p[i].numAttr+"</td>" +
            "<tr>";
        }
        components.innerHTML += newG;
    }
}

function showAttr(svgName, index, type, id) {
    var valueAttr = {"fileName": svgName, "index": index, "type": type, "id": id};

    $.ajax({
        type: 'get',           //Request type
        dataType: 'text',       //Data type - we will use JSON for almost everything 
        url: '/showAttr',          //The server endpoint we are connecting to
        contentType: 'application/json',
        data: valueAttr,
        success: function (data) {
            //alert('Successfully connected to the server');
            console.log('Successfully connected to the server');
            //console.log(data);

            //var parsedData = JSON.parse(data);
            //console.log("this: "+JSON.parse(data));
            buildAttr(data, svgName, index);
        },
        fail: function(error) {
            //alert('Failure to connect to the server');
            console.log('Failure to connect to the server'); 
        }
    });
}

function buildAttr(data, svgName, index) {

    var parse = JSON.parse(data);
    var id = JSON.parse(parse[0]).id;
    var info = JSON.parse(data);
    var info2 = JSON.parse(info[1]);
    console.log(info2);
    var box = document.getElementById(id);
    box.innerHTML = '';
    for(var i in info2) {
        var x = +i+ +1;
        var values = "<textarea id=\"textBox"+i+"\" onchange=\"editAttr(\'"+svgName+"\', \'"+index+"\', "+id+", \'textBox"+i+"\')\" rows=\"3\" cols=\"25\" text-align=\"center\" vertical-align=\"middle\">Attribute "+x+": [name="+info2[i].name+", value="+info2[i].value+"]</textarea>";
        console.log(values);
        box.innerHTML += values;
    }

}

function editAttr(svgName, index, col_id, textBox_id) {
    var check = document.getElementById(textBox_id).value;
    //Attribute 1: [name=sxd, value=#ffdd67]
    var indexOfName = check.indexOf("name=") + +5; 
    var indexOfValue = check.indexOf("value=") + +6; 
    var indexOfSep = check.indexOf(",");

    var newName = check.substring(indexOfName,indexOfSep);
    var newValue = check.substring(indexOfValue, check.length-1);
    console.log(svgName);
    var obj = {"fileName": svgName,"name": newName,"value": newValue};
    console.log(check);
    console.log(newName);
    console.log(newValue);
    
    $.ajax({
        type: 'get',           //Request type
        dataType: 'JSON',       //Data type - we will use JSON for almost everything 
        url: '/editAttr',          //The server endpoint we are connecting to
        contentType: 'application/json',
        data: obj,
        success: function (data) {
            //alert('Successfully connected to the server');
            console.log('Successfully connected to the server');
            //console.log(data);

            //var parsedData = JSON.parse(data);
            //console.log(parsedData);
            buildAttr(data);
        },
        fail: function(error) {
            //alert('Failure to connect to the server');
            console.log('Failure to connect to the server'); 
        }
    });

}