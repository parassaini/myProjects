// For an introduction to the Blank template, see the following documentation:
// http://go.microsoft.com/fwlink/?LinkID=392286
(function () {
    "use strict";

    var app = WinJS.Application;
    var activation = Windows.ApplicationModel.Activation;
    var canvas, context, stage;
    var bgImage, brImage, br2Image, br3Image,ban2Image, br4Image, quImage, pl1Image, pl2Image, pl3Image, pl4Image, pl5Image, pl6Image, pl7Image, pl8Image, pl9Image, pl10Image, pl11Image, pl12Image, pl13Image, pl14Image, pl15Image, pl16Image, prImage;
    var brBitmap, br2Bitmap, br3Bitmap, br4Bitmap, bgBitmap,ban2Bitmap, quBitmap, pl1Bitmap, pl2Bitmap, pl3Bitmap, pl4Bitmap, pl5Bitmap, pl6Bitmap, pl7Bitmap, pl8Bitmap, pl9Bitmap, pl10Bitmap, pl11Bitmap, pl12Bitmap, pl13Bitmap, pl14Bitmap, pl15Bitmap, pl16Bitmap, prBitmap;
    var queue;
    var playerX = 70;
    var playerY = 670;
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
                        { id: "bg", src: "images/inside.jpg" },
                        { id: "pl10", src: "images/pl10.png" },
                        { id: "pl11", src: "images/pl11.png" },
                        { id: "pl12", src: "images/pl12.png" },
                        { id: "pl13", src: "images/pl13.png" },
                        { id: "pl14", src: "images/pl14.png" },
                        { id: "pl15", src: "images/pl15.png" },
                        { id: "pl16", src: "images/pl16.png" },
                        { id: "pl1", src: "images/pl1.png" },
                        { id: "pl2", src: "images/pl2.png" },
                        { id: "pl3", src: "images/pl3.png" },
                        { id: "pl4", src: "images/pl4.png" },
                        { id: "pl5", src: "images/pl5.png" },
                        { id: "pl6", src: "images/pl6.png" },
                        { id: "pl7", src: "images/pl7.png" },
                        { id: "pl8", src: "images/pl8.png" },
                        { id: "pl9", src: "images/pl9.png" },
                        { id: "br", src: "images/pipe.png" },
                        { id: "qu", src: "images/18.jpg" },
                                { id: "ban2", src: "images/ban2 - Copy.png" }
            ]);
        }
        function prepareResume() {
            // Draw background first (other items appear on top)
            bgImage = queue.getResult("bg");
            bgBitmap = new createjs.Bitmap(bgImage).set({
                scaleX: 5,
                scaleY: 4.5,
                visible: true,
                x: 0,
                y: 0
            });
            stage.addChild(bgBitmap);

            ban2Image = queue.getResult("ban2");
            ban2Bitmap = new createjs.Bitmap(ban2Image).set({
                scaleX: 3,
                scaleY: 1,
                visible: true,
                x: 0,
                y: 0
            });
            stage.addChild(ban2Bitmap);

            brImage = queue.getResult("br");
            brBitmap = new createjs.Bitmap(brImage).set({
                scaleX: 0.4,
                scaleY: 0.7,
                visible: true,
                x: 300,
                y: 470

            });
            stage.addChild(brBitmap);

            name = new createjs.Text("C/C++", "15px Arial", "#ff7700").set({
                scaleX: 1,
                scaleY: 3,
                visible: true,
                x: 320,
                y: 430
            });
            stage.addChild(name);

            br2Image = queue.getResult("br");
            br2Bitmap = new createjs.Bitmap(br2Image).set({
                scaleX: 0.4,
                scaleY: 0.9,
                visible: true,
                x: 500,
                y: 395

            });
            stage.addChild(br2Bitmap);


            phone = new createjs.Text("Web Developent(HTML/CSS/JAVASCRIPT/JQUERY)", "15px Arial", "#ff7700").set({
                scaleX: 1,
                scaleY: 3,
                visible: true,
                x: 320,
                y: 350
            });
            stage.addChild(phone);

            br3Image = queue.getResult("br");
            br3Bitmap = new createjs.Bitmap(br3Image).set({
                scaleX: 0.4,
                scaleY: 1.1,
                visible: true,
                x: 700,
                y: 320

            });
            stage.addChild(br3Bitmap);


            email = new createjs.Text("Cross Platform Development(HTML/JAVASCRIPT)", "15px Arial", "#ff7700").set({
                scaleX: 1,
                scaleY: 3,
                visible: true,
                x: 600,
                y: 270
            });
            stage.addChild(email);

            br4Image = queue.getResult("br");
            br4Bitmap = new createjs.Bitmap(br4Image).set({
                scaleX: 0.4,
                scaleY: 1.3,
                visible: true,
                x: 1000,
                y: 240

            });
            stage.addChild(br4Bitmap);


            addr = new createjs.Text("Window Store And Phone(HTML/JAVASCRIPT)", "15px Arial", "#ff7700").set({
                scaleX: 1,
                scaleY: 3,
                visible: true,
                x: 900,
                y: 180
            });
            stage.addChild(addr);


            pl10Image = queue.getResult("pl10");
            pl10Bitmap = new createjs.Bitmap(pl10Image).set({
                scaleX: 1,
                scaleY: 1,
                visible: true,
                x: playerX,
                y: playerY
            });
            stage.addChild(pl10Bitmap);

            pl11Image = queue.getResult("pl11");
            pl11Bitmap = new createjs.Bitmap(pl11Image).set({
                scaleX: 1,
                scaleY: 1,
                visible: false,
                x: playerX,
                y: playerY
            });
            stage.addChild(pl11Bitmap);

            pl12Image = queue.getResult("pl12");
            pl12Bitmap = new createjs.Bitmap(pl12Image).set({
                scaleX: 1,
                scaleY: 1,
                visible: false,
                x: playerX,
                y: playerY
            });
            stage.addChild(pl12Bitmap);

            pl13Image = queue.getResult("pl13");
            pl13Bitmap = new createjs.Bitmap(pl13Image).set({
                scaleX: 1,
                scaleY: 1,
                visible: false,
                x: playerX,
                y: playerY
            });
            stage.addChild(pl13Bitmap);

            pl14Image = queue.getResult("pl14");
            pl14Bitmap = new createjs.Bitmap(pl14Image).set({
                scaleX: 1,
                scaleY: 1,
                visible: false,
                x: playerX,
                y: playerY
            });
            stage.addChild(pl14Bitmap);

            pl15Image = queue.getResult("pl15");
            pl15Bitmap = new createjs.Bitmap(pl15Image).set({
                scaleX: 1,
                scaleY: 1,
                visible: false,
                x: playerX,
                y: playerY
            });
            stage.addChild(pl15Bitmap);

            pl16Image = queue.getResult("pl16");
            pl16Bitmap = new createjs.Bitmap(pl16Image).set({
                scaleX: 1,
                scaleY: 1,
                visible: false,
                x: playerX,
                y: playerY
            });
            stage.addChild(pl16Bitmap);

            pl1Image = queue.getResult("pl1");
            pl1Bitmap = new createjs.Bitmap(pl1Image).set({
                scaleX: 1,
                scaleY: 1,
                visible: false,
                x: playerX,
                y: playerY
            });
            stage.addChild(pl1Bitmap);

            pl2Image = queue.getResult("pl2");
            pl2Bitmap = new createjs.Bitmap(pl2Image).set({
                scaleX: 1,
                scaleY: 1,
                visible: false,
                x: playerX,
                y: playerY
            });
            stage.addChild(pl2Bitmap);

            pl3Image = queue.getResult("pl3");
            pl3Bitmap = new createjs.Bitmap(pl3Image).set({
                scaleX: 1,
                scaleY: 1,
                visible: false,
                x: playerX,
                y: playerY
            });
            stage.addChild(pl3Bitmap);

            pl4Image = queue.getResult("pl4");
            pl4Bitmap = new createjs.Bitmap(pl4Image).set({
                scaleX: 1,
                scaleY: 1,
                visible: false,
                x: playerX,
                y: playerY
            });
            stage.addChild(pl4Bitmap);

            pl5Image = queue.getResult("pl5");
            pl5Bitmap = new createjs.Bitmap(pl5Image).set({
                scaleX: 1,
                scaleY: 1,
                visible: false,
                x: playerX,
                y: playerY
            });
            stage.addChild(pl5Bitmap);

            pl6Image = queue.getResult("pl6");
            pl6Bitmap = new createjs.Bitmap(pl6Image).set({
                scaleX: 1,
                scaleY: 1,
                visible: false,
                x: playerX,
                y: playerY
            });
            stage.addChild(pl6Bitmap);

            pl7Image = queue.getResult("pl7");
            pl7Bitmap = new createjs.Bitmap(pl7Image).set({
                scaleX: 1,
                scaleY: 1,
                visible: false,
                x: playerX,
                y: playerY
            });
            stage.addChild(pl7Bitmap);

            pl8Image = queue.getResult("pl8");
            pl8Bitmap = new createjs.Bitmap(pl8Image).set({
                scaleX: 1,
                scaleY: 1,
                visible: false,
                x: playerX,
                y: playerY
            });
            stage.addChild(pl8Bitmap);

            pl9Image = queue.getResult("pl9");
            pl9Bitmap = new createjs.Bitmap(pl9Image).set({
                scaleX: 1,
                scaleY: 1,
                visible: false,
                x: playerX,
                y: playerY
            });
            stage.addChild(pl9Bitmap);

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

        }
        function update()
        {
            if(playerX==1330)
            {
               
                next();
            }
        }
        function next()
        {
           
            window.location("finish.html");
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
                case KEYCODE_SPACE:
                case 87:  // W
                case 37:
                    jump();
                    break;

            }

        }

        function handleKeyUp(e) {

            switch (e.keyCode) {

            }
        }
        function jump() {
            j++;
            if (j == 2 * k)
                j = 1;
            i = j;
            

            jumpUp();
            run();
            jumpDown();
            run();
        }
        function jumpUp() {
            if (j < k) {

                playerY -= 5;
                if (pl10Bitmap.scaleX == -1)
                    playerX -= 3;
                else
                    playerX += 3;
                pl16Bitmap.y = pl15Bitmap.y = pl14Bitmap.y = pl13Bitmap.y = pl12Bitmap.y = pl11Bitmap.y = pl10Bitmap.y = pl9Bitmap.y = pl8Bitmap.y = pl7Bitmap.y = pl6Bitmap.y = pl5Bitmap.y = pl4Bitmap.y = pl3Bitmap.y = pl2Bitmap.y = pl1Bitmap.y = playerY;
                pl16Bitmap.x = pl15Bitmap.x = pl14Bitmap.x = pl13Bitmap.x = pl12Bitmap.x = pl11Bitmap.x = pl10Bitmap.x = pl9Bitmap.x = pl8Bitmap.x = pl7Bitmap.x = pl6Bitmap.x = pl5Bitmap.x = pl4Bitmap.x = pl3Bitmap.x = pl2Bitmap.x = pl1Bitmap.x = playerX;

            }

        }
        function jumpDown() {
            if (j < 2 * k && j > k) {
                playerY += 5;
                if (pl10Bitmap.scaleX == -1)
                    playerX -= 3;
                else
                    playerX += 3;
                pl16Bitmap.y = pl15Bitmap.y = pl14Bitmap.y = pl13Bitmap.y = pl12Bitmap.y = pl11Bitmap.y = pl10Bitmap.y = pl9Bitmap.y = pl8Bitmap.y = pl7Bitmap.y = pl6Bitmap.y = pl5Bitmap.y = pl4Bitmap.y = pl3Bitmap.y = pl2Bitmap.y = pl1Bitmap.y = playerY;
                pl16Bitmap.x = pl15Bitmap.x = pl14Bitmap.x = pl13Bitmap.x = pl12Bitmap.x = pl11Bitmap.x = pl10Bitmap.x = pl9Bitmap.x = pl8Bitmap.x = pl7Bitmap.x = pl6Bitmap.x = pl5Bitmap.x = pl4Bitmap.x = pl3Bitmap.x = pl2Bitmap.x = pl1Bitmap.x = playerX;
            }

        }
        function runRight() {
            if (playerY != 670) {
                playerY = 670;
                i = 10;
                j = 0;
            }
            i++;
            playerX += 5;
            pl16Bitmap.y = pl15Bitmap.y = pl14Bitmap.y = pl13Bitmap.y = pl12Bitmap.y = pl11Bitmap.y = pl10Bitmap.y = pl9Bitmap.y = pl8Bitmap.y = pl7Bitmap.y = pl6Bitmap.y = pl5Bitmap.y = pl4Bitmap.y = pl3Bitmap.y = pl2Bitmap.y = pl1Bitmap.y = playerY;

            pl10Bitmap.scaleX = pl11Bitmap.scaleX = pl12Bitmap.scaleX = pl13Bitmap.scaleX = pl14Bitmap.scaleX = pl15Bitmap.scaleX = pl16Bitmap.scaleX = pl1Bitmap.scaleX = pl2Bitmap.scaleX = pl3Bitmap.scaleX = pl4Bitmap.scaleX = pl5Bitmap.scaleX = pl6Bitmap.scaleX = pl7Bitmap.scaleX = pl8Bitmap.scaleX = pl9Bitmap.scaleX = 1;
            pl16Bitmap.x = pl15Bitmap.x = pl14Bitmap.x = pl13Bitmap.x = pl12Bitmap.x = pl11Bitmap.x = pl10Bitmap.x = pl9Bitmap.x = pl8Bitmap.x = pl7Bitmap.x = pl6Bitmap.x = pl5Bitmap.x = pl4Bitmap.x = pl3Bitmap.x = pl2Bitmap.x = pl1Bitmap.x = playerX;

            run();


        }
        function runLeft() {

            if (playerY != 670) {
                playerY = 670;
                i = 10;
                j = 0;
            }
            i++;
            playerX -= 5;
            pl16Bitmap.y = pl15Bitmap.y = pl14Bitmap.y = pl13Bitmap.y = pl12Bitmap.y = pl11Bitmap.y = pl10Bitmap.y = pl9Bitmap.y = pl8Bitmap.y = pl7Bitmap.y = pl6Bitmap.y = pl5Bitmap.y = pl4Bitmap.y = pl3Bitmap.y = pl2Bitmap.y = pl1Bitmap.y = playerY;

            pl10Bitmap.scaleX = pl11Bitmap.scaleX = pl12Bitmap.scaleX = pl13Bitmap.scaleX = pl14Bitmap.scaleX = pl15Bitmap.scaleX = pl16Bitmap.scaleX = pl1Bitmap.scaleX = pl2Bitmap.scaleX = pl3Bitmap.scaleX = pl4Bitmap.scaleX = pl5Bitmap.scaleX = pl6Bitmap.scaleX = pl7Bitmap.scaleX = pl8Bitmap.scaleX = pl9Bitmap.scaleX = -1;
            if (playerX < 40)
            { playerX = 40; }
            pl16Bitmap.x = pl15Bitmap.x = pl14Bitmap.x = pl13Bitmap.x = pl12Bitmap.x = pl11Bitmap.x = pl10Bitmap.x = pl9Bitmap.x = pl8Bitmap.x = pl7Bitmap.x = pl6Bitmap.x = pl5Bitmap.x = pl4Bitmap.x = pl3Bitmap.x = pl2Bitmap.x = pl1Bitmap.x = playerX;

            run();


        }
        function run() {
           
            if (p == 50 || p == 1) {
                createjs.Sound.registerPlugins([createjs.HTMLAudioPlugin]);
                console.log(createjs.Sound.activePlugin.toString());
                createjs.Sound.alternateExtensions = ["ogg"];
                var mySound = createjs.Sound.play("castle_clear.mp3");
                p = 2;
            }
            p++;
            if (i == 10) {

                pl10Bitmap.visible = true;
                pl11Bitmap.visible = false;
                pl12Bitmap.visible = false;
                pl13Bitmap.visible = false;
                pl14Bitmap.visible = false;
                pl15Bitmap.visible = false;
                pl16Bitmap.visible = false;
                pl1Bitmap.visible = false;
                pl2Bitmap.visible = false;
                pl3Bitmap.visible = false;
                pl4Bitmap.visible = false;
                pl5Bitmap.visible = false;
                pl6Bitmap.visible = false;
                pl7Bitmap.visible = false;
                pl8Bitmap.visible = false;
                pl9Bitmap.visible = false;

            }
            if (i == 11) {

                pl10Bitmap.visible = false;
                pl11Bitmap.visible = true;
                pl12Bitmap.visible = false;
                pl13Bitmap.visible = false;
                pl14Bitmap.visible = false;
                pl15Bitmap.visible = false;
                pl16Bitmap.visible = false;
                pl1Bitmap.visible = false;
                pl2Bitmap.visible = false;
                pl3Bitmap.visible = false;
                pl4Bitmap.visible = false;
                pl5Bitmap.visible = false;
                pl6Bitmap.visible = false;
                pl7Bitmap.visible = false;
                pl8Bitmap.visible = false;
                pl9Bitmap.visible = false;

            }
            if (i == 12) {

                pl10Bitmap.visible = false;
                pl11Bitmap.visible = false;
                pl12Bitmap.visible = true;
                pl13Bitmap.visible = false;
                pl14Bitmap.visible = false;
                pl15Bitmap.visible = false;
                pl16Bitmap.visible = false;
                pl1Bitmap.visible = false;
                pl2Bitmap.visible = false;
                pl3Bitmap.visible = false;
                pl4Bitmap.visible = false;
                pl5Bitmap.visible = false;
                pl6Bitmap.visible = false;
                pl7Bitmap.visible = false;
                pl8Bitmap.visible = false;
                pl9Bitmap.visible = false;
            }
            if (i == 13) {

                pl10Bitmap.visible = false;
                pl11Bitmap.visible = false;
                pl12Bitmap.visible = false;
                pl13Bitmap.visible = true;
                pl14Bitmap.visible = false;
                pl15Bitmap.visible = false;
                pl16Bitmap.visible = false;
                pl1Bitmap.visible = false;
                pl2Bitmap.visible = false;
                pl3Bitmap.visible = false;
                pl4Bitmap.visible = false;
                pl5Bitmap.visible = false;
                pl6Bitmap.visible = false;
                pl7Bitmap.visible = false;
                pl8Bitmap.visible = false;
                pl9Bitmap.visible = false;

            }
            if (i == 14) {

                pl10Bitmap.visible = false;
                pl11Bitmap.visible = false;
                pl12Bitmap.visible = false;
                pl13Bitmap.visible = false;
                pl14Bitmap.visible = true;
                pl15Bitmap.visible = false;
                pl16Bitmap.visible = false;
                pl1Bitmap.visible = false;
                pl2Bitmap.visible = false;
                pl3Bitmap.visible = false;
                pl4Bitmap.visible = false;
                pl5Bitmap.visible = false;
                pl6Bitmap.visible = false;
                pl7Bitmap.visible = false;
                pl8Bitmap.visible = false;
                pl9Bitmap.visible = false;

            }
            if (i == 15) {

                pl10Bitmap.visible = false;
                pl11Bitmap.visible = false;
                pl12Bitmap.visible = false;
                pl13Bitmap.visible = false;
                pl14Bitmap.visible = false;
                pl15Bitmap.visible = true;
                pl16Bitmap.visible = false;
                pl1Bitmap.visible = false;
                pl2Bitmap.visible = false;
                pl3Bitmap.visible = false;
                pl4Bitmap.visible = false;
                pl5Bitmap.visible = false;
                pl6Bitmap.visible = false;
                pl7Bitmap.visible = false;
                pl8Bitmap.visible = false;
                pl9Bitmap.visible = false;

            }
            if (i == 16) {

                pl10Bitmap.visible = false;
                pl11Bitmap.visible = false;
                pl12Bitmap.visible = false;
                pl13Bitmap.visible = false;
                pl14Bitmap.visible = false;
                pl15Bitmap.visible = false;
                pl16Bitmap.visible = true;
                pl1Bitmap.visible = false;
                pl2Bitmap.visible = false;
                pl3Bitmap.visible = false;
                pl4Bitmap.visible = false;
                pl5Bitmap.visible = false;
                pl6Bitmap.visible = false;
                pl7Bitmap.visible = false;
                pl8Bitmap.visible = false;
                pl9Bitmap.visible = false;

            }
            if (i == 1) {

                pl10Bitmap.visible = false;
                pl11Bitmap.visible = false;
                pl12Bitmap.visible = false;
                pl13Bitmap.visible = false;
                pl14Bitmap.visible = false;
                pl15Bitmap.visible = false;
                pl16Bitmap.visible = false;
                pl1Bitmap.visible = true;
                pl2Bitmap.visible = false;
                pl3Bitmap.visible = false;
                pl4Bitmap.visible = false;
                pl5Bitmap.visible = false;
                pl6Bitmap.visible = false;
                pl7Bitmap.visible = false;
                pl8Bitmap.visible = false;
                pl9Bitmap.visible = false;

            }
            if (i == 2) {

                pl10Bitmap.visible = false;
                pl11Bitmap.visible = false;
                pl12Bitmap.visible = false;
                pl13Bitmap.visible = false;
                pl14Bitmap.visible = false;
                pl15Bitmap.visible = false;
                pl16Bitmap.visible = false;
                pl1Bitmap.visible = false;
                pl2Bitmap.visible = true;
                pl3Bitmap.visible = false;
                pl4Bitmap.visible = false;
                pl5Bitmap.visible = false;
                pl6Bitmap.visible = false;
                pl7Bitmap.visible = false;
                pl8Bitmap.visible = false;
                pl9Bitmap.visible = false;

            }
            if (i == 3) {

                pl10Bitmap.visible = false;
                pl11Bitmap.visible = false;
                pl12Bitmap.visible = false;
                pl13Bitmap.visible = false;
                pl14Bitmap.visible = false;
                pl15Bitmap.visible = false;
                pl16Bitmap.visible = false;
                pl1Bitmap.visible = false;
                pl2Bitmap.visible = false;
                pl3Bitmap.visible = true;
                pl4Bitmap.visible = false;
                pl5Bitmap.visible = false;
                pl6Bitmap.visible = false;
                pl7Bitmap.visible = false;
                pl8Bitmap.visible = false;
                pl9Bitmap.visible = false;

            }
            if (i == 4) {

                pl10Bitmap.visible = false;
                pl11Bitmap.visible = false;
                pl12Bitmap.visible = false;
                pl13Bitmap.visible = false;
                pl14Bitmap.visible = false;
                pl15Bitmap.visible = false;
                pl16Bitmap.visible = false;
                pl1Bitmap.visible = false;
                pl2Bitmap.visible = false;
                pl3Bitmap.visible = false;
                pl4Bitmap.visible = true;
                pl5Bitmap.visible = false;
                pl6Bitmap.visible = false;
                pl7Bitmap.visible = false;
                pl8Bitmap.visible = false;
                pl9Bitmap.visible = false;

            }
            if (i == 5) {

                pl10Bitmap.visible = false;
                pl11Bitmap.visible = false;
                pl12Bitmap.visible = false;
                pl13Bitmap.visible = false;
                pl14Bitmap.visible = false;
                pl15Bitmap.visible = false;
                pl16Bitmap.visible = false;
                pl1Bitmap.visible = false;
                pl2Bitmap.visible = false;
                pl3Bitmap.visible = false;
                pl4Bitmap.visible = false;
                pl5Bitmap.visible = true;
                pl6Bitmap.visible = false;
                pl7Bitmap.visible = false;
                pl8Bitmap.visible = false;
                pl9Bitmap.visible = false;
            }
            if (i == 6) {

                pl10Bitmap.visible = false;
                pl11Bitmap.visible = false;
                pl12Bitmap.visible = false;
                pl13Bitmap.visible = false;
                pl14Bitmap.visible = false;
                pl15Bitmap.visible = false;
                pl16Bitmap.visible = false;
                pl1Bitmap.visible = false;
                pl2Bitmap.visible = false;
                pl3Bitmap.visible = false;
                pl4Bitmap.visible = false;
                pl5Bitmap.visible = false;
                pl6Bitmap.visible = true;
                pl7Bitmap.visible = false;
                pl8Bitmap.visible = false;
                pl9Bitmap.visible = false;
            }
            if (i == 7) {

                pl10Bitmap.visible = false;
                pl11Bitmap.visible = false;
                pl12Bitmap.visible = false;
                pl13Bitmap.visible = false;
                pl14Bitmap.visible = false;
                pl15Bitmap.visible = false;
                pl16Bitmap.visible = false;
                pl1Bitmap.visible = false;
                pl2Bitmap.visible = false;
                pl3Bitmap.visible = false;
                pl4Bitmap.visible = false;
                pl5Bitmap.visible = false;
                pl6Bitmap.visible = false;
                pl7Bitmap.visible = true;
                pl8Bitmap.visible = false;
                pl9Bitmap.visible = false;

            }
            if (i == 8) {

                pl10Bitmap.visible = false;
                pl11Bitmap.visible = false;
                pl12Bitmap.visible = false;
                pl13Bitmap.visible = false;
                pl14Bitmap.visible = false;
                pl15Bitmap.visible = false;
                pl16Bitmap.visible = false;
                pl1Bitmap.visible = false;
                pl2Bitmap.visible = false;
                pl3Bitmap.visible = false;
                pl4Bitmap.visible = false;
                pl5Bitmap.visible = false;
                pl6Bitmap.visible = false;
                pl7Bitmap.visible = false;
                pl8Bitmap.visible = true;
                pl9Bitmap.visible = false;
            }
            if (i == 9) {

                pl10Bitmap.visible = false;
                pl11Bitmap.visible = false;
                pl12Bitmap.visible = false;
                pl13Bitmap.visible = false;
                pl14Bitmap.visible = false;
                pl15Bitmap.visible = false;
                pl16Bitmap.visible = false;
                pl1Bitmap.visible = false;
                pl2Bitmap.visible = false;
                pl3Bitmap.visible = false;
                pl4Bitmap.visible = false;
                pl5Bitmap.visible = false;
                pl6Bitmap.visible = false;
                pl7Bitmap.visible = false;
                pl8Bitmap.visible = false;
                pl9Bitmap.visible = true;
            }
            if (i == 16)
                i = 1;

            stage.update();
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

   