#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
  //ofSetLogLevel(OF_LOG_NOTICE);
  ofSetLogLevel(OF_LOG_VERBOSE);
  ofRegisterURLNotification(this);  
  string url = "http://insta-search.herokuapp.com/images.xml";
  loadXmlId = ofLoadURLAsync(url,"load");    
}

    
void testApp::urlResponse(ofHttpResponse &httpResponse){    
  if(httpResponse.request.getID() == loadXmlId && httpResponse.status==200 ){  // i.e is it ok  
    xml.loadFromBuffer(httpResponse.data.getText()); 
    processXml();
  } 
}  

//--------------------------------------------------------------
void testApp::processXml(){
  xml.pushTag("response");
  xml.pushTag("data");

  int numTags = xml.getNumTags("data");
  for (int i = 0; i < numTags; i++){
    cout << xml.getValue("data:type","-", i) << endl;
    string media_url = xml.getValue("data:url", "-", i);
    if (media_url != "-"){
      ofLogNotice() << "Download media: " << ofFilePath::getFileName(media_url);
      ofSaveURLAsync(media_url,ofFilePath::getFileName(media_url));
      //ofSaveURLTo(media_url,ofFilePath::getFileName(media_url));
    }
  }
}

//--------------------------------------------------------------
void testApp::update(){
}

//--------------------------------------------------------------
void testApp::draw(){
  x++;
  if (x > ofGetWidth() || x > ofGetHeight()){
    x = 0;
  }

  ofRect(x,x, 20,20);

}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
  switch(key){
    case 'f':
      ofToggleFullscreen();
      break;
    default:
      break;
  }
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}
