'use strict'

// C library API
const ffi = require('ffi-napi');

// Express App (Routes)
const express = require("express");
const app = express();
const path = require("path");
const fileUpload = require('express-fileupload');

app.use(fileUpload());
app.use(express.static(path.join(__dirname + '/uploads')));

// Minimization
const fs = require('fs');
const JavaScriptObfuscator = require('javascript-obfuscator');

// Important, pass in port as in `npm run dev 1234`, do not change
const portNum = process.argv[2];

var g;

// Send HTML at root, do not change
app.get('/', function (req, res) {
	res.sendFile(path.join(__dirname + '/public/index.html'));
});

// Send Style, do not change
app.get('/style.css', function (req, res) {
  //Feel free to change the contents of style.css to prettify your Web app
  res.sendFile(path.join(__dirname + '/public/style.css'));
});

// Send obfuscated JS, do not change
app.get('/index.js', function (req, res) {
	fs.readFile(path.join(__dirname + '/public/index.js'), 'utf8', function (err, contents) {
		const minimizedContents = JavaScriptObfuscator.obfuscate(contents, { compact: true, controlFlowFlattening: true });
		res.contentType('application/javascript');
		res.send(minimizedContents._obfuscatedCode);
	});
});

//Respond to POST requests that upload files to uploads/ directory
app.post('/upload', function (req, res) {
	if (!req.files) {
		return res.status(400).send('No files were uploaded.');
	}

	let uploadFile = req.files.uploadFile;

	g;
	const dir = __dirname + '/uploads/';
	const schema = __dirname + '/parser/' + 'svg.xsd';
	const svgName = '.svg';
	var fileNameInServer;
	var doesNotExist = true;
	var sendBackBool = false;
	var returnString = "{\"uploadedFileName\":";
	var jsonObj;

	if(uploadFile.name.indexOf(svgName) !== -1) {
		fileNameInServer = fs.readdirSync(dir);
		for(var i in fileNameInServer) {
			if(fileNameInServer[i] === uploadFile.name) {
				returnString = returnString + "\""+ uploadFile.name +"\",\"returnMessage\":\"Already exists on the server.\"}";
				//console.log(returnString);
				doesNotExist = false;
			}
		}
	}
	else
	{
		returnString = returnString + "\""+ uploadFile.name +"\",\"returnMessage\":\"is not a valid svg file.\"}";
		//console.log(returnString);
	}

	if(doesNotExist) {
		var newFile = libsvgparse.validSVGToJSON(dir + uploadFile.name, schema);
		if(newFile === null)
		{
			returnString = returnString + "\""+ uploadFile.name +"\",\"returnMessage\":\"is not a valid svg file.\"}";
			//console.log(returnString);
		}
	}
	else
	{
		// Use the mv() method to place the file somewhere on your server
		uploadFile.mv('uploads/' + uploadFile.name, function (err) {
			returnString = returnString + "\""+ uploadFile.name +"\",\"returnMessage\":\"was uploaded successfully.\"}";
			if (err) {
				returnString = returnString + "\""+ uploadFile.name +"\",\"returnMessage\":\"Error.\"}";
				console.log("Error.");
				res.status(500).send(err);
				return;
			}
		});
	}
	jsonObj = JSON.parse(returnString);
	g = jsonObj;

	console.log("jsonObj: " + JSON.stringify(jsonObj));
	app.get('/alertMessage', function (req, res) {
		//console.log("m: " + JSON.stringify(g));
		res.send(g);
	});

	res.redirect('/');
});

//Respond to GET requests for files in the uploads/ directory
app.get('/uploads/:name', function (req, res) {
	fs.stat('uploads/' + req.params.name, function (err, stat) {
		if (err == null) {
			res.sendFile(path.join(__dirname + '/uploads/' + req.params.name));
		} else {
			console.log('Error in file downloading route: ' + err);
			res.send('');
		}
	});
});

//******************** Your code goes here ******************** 

let libsvgparse = ffi.Library('./libsvgparse', {
  	'validSVGToJSON': [ 'string', ['string', 'string'] ],    //return type first, argument list second
  	'SVGrectListToJSON': [ 'string', ['string', 'string'] ],    //for void input type, leave argument list empty
  	'SVGcircListToJSON': [ 'string', ['string', 'string'] ], 
  	'SVGpathListToJSON': [ 'string', ['string', 'string'] ], 
  	'SVGgroupListToJSON': [ 'string', ['string', 'string'] ], 
  	'titleAndDesc': [ 'string', ['string', 'string'] ],
  	'showAttr': [ 'string', ['string', 'string', 'int', 'string'] ],
  	'editAttr': [ 'void', ['string', 'string', 'int', 'string', 'string', 'string'] ],
  });

//Sample endpoint
app.get('/someendpoint', function(req , res){
	let retStr = req.query.name1 + " " + req.query.name2;
	res.send({
		foo: retStr
	});
});

app.listen(portNum);
console.log('Running app at localhost: ' + portNum);

//console.log('Path: ' + String(path.join(__dirname + '/uploads')));

const dir = __dirname + '/uploads/';
const schema = __dirname + '/parser/' + 'svg.xsd';
const svgName = '.svg';
var fileName = "";
var fileSize = "";
var size;
var addToTable;

app.get('/editAttr', function (req, res) {
	var fileName = req.query.fileName;
	var name = req.query.name;
	var value = req.query.value;
	
	//libsvgparse.editAttr(dir + fileName, schema, index, type, name, value);


	//console.log(JSON.parse(returnObj));
	//res.send(list);
});

app.get('/showAttr', function (req, res) {
	var fileName = req.query.fileName;
	var index = req.query.index;
	var type = req.query.type;
	var returnObj;
	var list = [];

	var files = fs.readdirSync(dir);
	list.push(JSON.stringify(req.query));

	for(var i in files) {
		if(files[i] === fileName) {
			returnObj = libsvgparse.showAttr(dir + fileName, schema, index, type);
			list.push(returnObj);
		}
	}
	//console.log(JSON.parse(returnObj));
	res.send(list);
});


app.get('/value', function (req, res) {

	var svgNameFromClient = req.query.fileName;
	//var svgNameFromClient = JSON.stringify(req.query);
	//var nameObj = {};
	//nameObj = JSON.parse(svgNameFromClient);
	//svgNameFromClient = JSON.parse(req.query);
	var rectObj;
	var circObj;
	var pathObj;
	var groupObj;
	var tAndD;
	var total = [];
	console.log("TEST TEST: "+ svgNameFromClient);

	var files = fs.readdirSync(dir);
	for(var i in files) {
		if(files[i] === svgNameFromClient) {
			var str = "{\"fileName\":\""+svgNameFromClient+"\"}";
			tAndD = libsvgparse.titleAndDesc(dir +svgNameFromClient, schema);
			rectObj = libsvgparse.SVGrectListToJSON(dir +svgNameFromClient, schema);
			circObj = libsvgparse.SVGcircListToJSON(dir +svgNameFromClient, schema);
			pathObj = libsvgparse.SVGpathListToJSON(dir +svgNameFromClient, schema);
			groupObj = libsvgparse.SVGgroupListToJSON(dir +svgNameFromClient, schema);

			/*
			var g = JSON.parse(groupObj);

			console.log("tAndD: "+tAndD);
			console.log("r: "+rectObj);
			console.log("c: "+circObj);
			console.log("p: "+pathObj);
			console.log("g: "+groupObj);
			console.log("g children: "+g[0].children);
			console.log("g attr: "+g[0].numAttr);
			*/

			/*
			var s = "{\"title\":\"\",\"desc\":\"\"}";
			var s2 = JSON.parse(s);
			console.log("title: "+s2.title);
			console.log("desc: "+s2.desc);
			*/
			
			//console.log(tAndD);

			total.push(JSON.parse(str));
			total.push(JSON.parse(tAndD));
			total.push(JSON.parse(rectObj));
			total.push(JSON.parse(circObj));
			total.push(JSON.parse(pathObj));
			total.push(JSON.parse(groupObj));

			//doesNotExist = false;
		}
	}

	res.send(total);
});


app.get('/addToWebsite', function(req, res){
	
	//JSON name: {"fileName":string}
	//JSON name: {"fileSize":string}
	var send = [];
	var addToTable2;
	var obj = [];
	var str = "";
	var files = fs.readdirSync(dir);
	for (var i in files) {
	//var definition = require('./application/models/' + files[i]).Model;
	//console.log('Model Loaded: ' + files[i]);
	if(files[i].indexOf(svgName) !== -1) {
		//fileDir = dir + files[i];
		//console.log("DIR: "+dir + files[i]);
		str = libsvgparse.validSVGToJSON(dir + files[i], schema);
		if(str !== null) {
			fileName = ",\"fileName\":\""+files[i]+"\"";
			size = fs.statSync(dir + files[i])
			//console.log("SIZE: "+ (size.size));
			fileSize = ",\"fileSize\":\""+formatBytes(size.size)+"\"}";
			//console.log("INSIDE: "+ fileName);
			fileName = fileName + fileSize;
			str = str.substring(0, str.length - 1);
			str = str + fileName;
			//console.log("INSIDE2: "+ str);

			addToTable2 = JSON.parse(str);
			obj.push(addToTable2);
		}
		//console.log("i: "+ i + addToTable2[i]);
	}
}


for(var j = 0; j < obj.length; j++) {
	if(obj[j] !== null) {
			//console.log(addToTable2[j]);
			send.push(obj[j]);
			//console.log("j: " + j + send[j]);
		}
	}

	res.send(send);
});


//Reference statoverflow
function formatBytes(bytes, decimals = 2) {
	if (bytes === 0) return '0 Bytes';

	const k = 1024;
	const dm = decimals < 0 ? 0 : decimals;
	const sizes = ['Bytes', 'KB', 'MB', 'GB', 'TB', 'PB', 'EB', 'ZB', 'YB'];

	const i = Math.floor(Math.log(bytes) / Math.log(k));

	return parseFloat((bytes / Math.pow(k, i)).toFixed(dm)) + ' ' + sizes[i];
}