// For an introduction to the Blank template, see the following documentation:
// http://go.microsoft.com/fwlink/?LinkID=392286
(function () {
    "use strict";

    var app = WinJS.Application;
    var activation = Windows.ApplicationModel.Activation;
    var canvas, context, stage;
    var bgImage, brImage, br2Image, br3Image, br4Image, quImage,ban1Image, prImage,bgImage,bg1Image,bg2Image,bg3Image,boImage;
    var brBitmap, br2Bitmap, br3Bitmap, br4Bitmap,ban1Bitmap, bgBitmap, quBitmap, bgBitmap,bg1Bitmap,bg2Bitmap,bg3Bitmap,boBitmap;
    var queue;
    var playerX = 70;
    var playerY = 190;
    var KEYCODE_LEFT = 37;
    var KEYCODE_RIGHT = 39;
    var KEYCODE_SPACE = 32;
    var keys = [];
    var k = 40, i = 10, j = 0, m = 1,p=1;
    var ss, grant;
    var name, phone, email, addr;
    app.onactivated = function (args) {
        if (args.detail.kind === activation.ActivationKind.launch) {
            if (args.detail.previousExecutionState !== activation.ApplicationExecutionState.terminated) {
                // TODO: This application has been newly launched. Initialize
                // your application here.
            }
            else {
                // TODO: This application has been reactivated from suspension. 
                // Restore application state here. 
            }
            args.setPromise(WinJS.UI.processAll());
        }
    };

    function initialize() {
        canvas = document.getElementById("resume");
        canvas.width = window.innerWidth;
        canvas.height = window.innerHeight;
        context = canvas.getContext("2D");
        stage = new createjs.Stage(canvas);

        document.onkeydown = handleKeyDown;
        document.onkeyup = handleKeyUp;



        //use queue to make sure sounds & images are loaded before we begin processing
        // (Especially important for large/remote resources)
        queue = new createjs.LoadQueue();
        queue.addEventListener("complete", prepareResume)
        queue.loadManifest([
                    { id: "bg", src: "images/5855.jpg" },
                    { id: "bg1", src: "images/5851.jpg" },
                    { id: "bg2", src: "images/5853 - Copy.jpg" },
                    { id: "br", src: "images/pipe.png" },
                    {id:"bo",src:"images/bo - Copy.png"},
                 { id: "bg3", src: "images/5852.jpg" },
                 {id:"ban1",src:"images/ban1 - Copy.png"}
        ]);

    }
    function prepareResume() {
        // Draw background first (other items appear on top)
        bgImage = queue.getResult("bg");
        bgBitmap = new createjs.Bitmap(bgImage).set({
            scaleX: 3,
            scaleY: 6,
            visible: true,
            x: 0,
            y:200
        });
        stage.addChild(bgBitmap);

        bg1Image = queue.getResult("bg1");
        bg1Bitmap = new createjs.Bitmap(bg1Image).set({
            scaleX: 3,
            scaleY: 1,
            visible: true,
            x: 0,
            y: 100
        });
        stage.addChild(bg1Bitmap);

        bg2Image = queue.getResult("bg2");
        bg2Bitmap = new createjs.Bitmap(bg2Image).set({
            scaleX: 3,
            scaleY: 4,
            visible: true,
            x: 0,
            y: 0
        });
        stage.addChild(bg2Bitmap);


        ban1Image = queue.getResult("ban1");
        ban1Bitmap = new createjs.Bitmap(ban1Image).set({
            scaleX: 3,
            scaleY: 1,
            visible: true,
            x: 30,
            y: 0
        });
        stage.addChild(ban1Bitmap);


        bg3Image = queue.getResult("bg3");
        bg3Bitmap = new createjs.Bitmap(bg3Image).set({
            scaleX: 3,
            scaleY: 2,
            visible: true,
            x: 0,
            y: 710
        });
        stage.addChild(bg3Bitmap);


        brImage = queue.getResult("br");
        brBitmap = new createjs.Bitmap(brImage).set({
            scaleX: 0.4,
            scaleY: 0.7,
            visible: true,
            x: 300,
            y: 440

        });
        stage.addChild(brBitmap);

        name = new createjs.Text("Learning Anything New", "15px Arial", "#ff7700").set({
            scaleX: 1,
            scaleY: 3,
            visible: true,
            x: 300,
            y: 390
        });
        stage.addChild(name);

        br2Image = queue.getResult("br");
        br2Bitmap = new createjs.Bitmap(br2Image).set({
            scaleX: 0.4,
            scaleY: 0.9,
            visible: true,
            x: 500,
            y: 365

        });
        stage.addChild(br2Bitmap);


        phone = new createjs.Text("Wandering Around", "15px Arial", "#ff7700").set({
            scaleX: 1,
            scaleY: 3,
            visible: true,
            x: 500,
            y: 320
        });
        stage.addChild(phone);

        br3Image = queue.getResult("br");
        br3Bitmap = new createjs.Bitmap(br3Image).set({
            scaleX: 0.4,
            scaleY: 1.1,
            visible: true,
            x: 700,
            y: 290

        });
        stage.addChild(br3Bitmap);


        email = new createjs.Text("Singing(Bathroom)", "15px Arial", "#ff7700").set({
            scaleX: 1,
            scaleY: 3,
            visible: true,
            x: 700,
            y: 240
        });
        stage.addChild(email);

        br4Image = queue.getResult("br");
        br4Bitmap = new createjs.Bitmap(br4Image).set({
            scaleX: 0.4,
            scaleY: 1.3,
            visible: true,
            x: 1000,
            y: 210

        });
        stage.addChild(br4Bitmap);


        addr = new createjs.Text("Travelling", "15px Arial", "#ff7700").set({
            scaleX: 1,
            scaleY: 3,
            visible: true,
            x: 1000,
            y: 150
        });
        stage.addChild(addr);

        boImage = queue.getResult("bo");
        boBitmap = new createjs.Bitmap(boImage).set({
            scaleX: -0.3,
            scaleY: 0.3,
            visible: true,
            x: 100,
            y: 70
        });
        stage.addChild(boBitmap);


        stage.update();
        start();
    }
    function start() {
        createjs.Ticker.setFPS(60);
        createjs.Ticker.addEventListener("tick", stage);
        createjs.Ticker.addEventListener("tick", loop);
    }
    function loop() {

       

        update();

    } function update() {
        if (playerX == 1330) {
            next();
        }
    }
    function next() {
        window.location("inside.html");
    }
    function handleKeyDown(e) {
        switch (e.keyCode) {
            case KEYCODE_LEFT:
            case 65:  // A
                runLeft();
                break;
            case KEYCODE_RIGHT:
            case 68:  // D
                runRight();
                break;
    
        }

    }

    function handleKeyUp(e) {

        switch (e.keyCode) {

        }
    }
    
    function runRight() {
        i++;
        playerX += 5;
        boBitmap.x = playerX;
        if(p==50||p==1){
        createjs.Sound.registerPlugins([createjs.HTMLAudioPlugin]);
        console.log(createjs.Sound.activePlugin.toString());
        createjs.Sound.alternateExtensions = ["ogg"];
        var mySound = createjs.Sound.play("Thunder1.mp3");
        p=2;
    }
    p++;}
    function runLeft() {
        playerX -= 5;
        boBitmap.x = playerX;;
        if(p==50||p==1){
        createjs.Sound.registerPlugins([createjs.HTMLAudioPlugin]);
        console.log(createjs.Sound.activePlugin.toString());
        createjs.Sound.alternateExtensions = ["ogg"];
        var mySound = createjs.Sound.play("Thunder1.mp3");
        p=2;
    }
    p++;
    }
    app.oncheckpoint = function (args) {
        // TODO: This application is about to be suspended. Save any state 
        // that needs to persist across suspension here. You might use the 
        // WinJS.Application.sessionState object, which is automatically 
        // saved and restored across suspension. If you need to complete an 
        // asynchronous operation before your application is suspended, call 
        // args.setPromise(). 
    };
    document.addEventListener("DOMContentLoaded", initialize, false);

    app.start();
})();

