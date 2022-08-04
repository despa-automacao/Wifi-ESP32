#include <WebServer.h>
#include <WiFi.h>
#include <WiFiManager.h> // https://github.com/tzapu/WiFiManager

//Prototipagem da função getPage, função completa após o loop
String getPage();

//Criando objeto do servidor web
WebServer server ( 80 );

//------PLACEHOLDER, REMOVER QUANDO IMPLEMENTAR LOCALAP -------------
//Atribuindo variaveis de SSID e senha para o servidor
const char* ssid = "M";
const char* password = "automacao";


//Conexão WIFI ---- PLACEHOLDER, IMPLEMENTAR LOCAL AP DEPOIS
void connectToWifi() {
  WiFi.mode(WIFI_STA);
  WiFiManager wm;
  wm.resetSettings();

  bool res;
  res = wm.autoConnect("AutoConnectAP","password"); // password protected ap
  if(!res){
    Serial.println("failed to connect");
    }else{
      Serial.println("Connected!");
      }
}

//Verifica se o pedido tem algum argumento, caso contrário, cria a página HTML
void handleRoot() {
  server.send(200, "text/html", getPage());
}


//Função para iniciar o servidor web
void beginServer() {
  server.on("/", handleRoot);
  server.begin();
  Serial.println("Servidor HTTP iniciado");
}


//FUNÇÃO PLACEHOLDER COLOCAR NO CÓDIGO CASO SEJA NECESSÁRIO INPUT REMOTO PARA O ESP32
void handleSubmit() {}

//----------------------INICIO FUNÇÃO SETUP------------------------------
void setup() {
  //Iniciando monitor serial
  Serial.begin(9600);
  //Conectando ao WIFI
  connectToWifi();
  //Chamada da função de inicio do servidor web
  beginServer();
}
//----------------------FINAL FUNÇÃO SETUP-------------------------------

//--------------------INICIO FUNÇÃO LOOP---------------------------------
void loop() {
  // put your main code here, to run repeatedly:
  server.handleClient();
  delay(1000);
}
//----------------------FINAL FUNÇÃO LOOP---------------------------------

//----------------PLACEHOLDER, COMPLETAR PÁGINA E IMPLEMENTAR MONITORAMENTO REMOTO EM TEMPO REAL-----------------------------------
//Função getPage, todo o código HTML da página servidor web será colocado aqui
//Programação em HTML deverá ser feita a parte e colada aqui
String getPage() {
  String page = "<html lang=en-EN<head><meta http-equiv='refresh' content='60'/>";
  page += "<title>Teste de servidor ESP32</title>";
  page += "<style> body { background-color: #fffff; font-family: Arial, Helvetica, Sans-Serif; Color : #000000}</style>";
  page += "</head><body><h1>Teste Servidor</h1>";
  page += "</body></html>";
}
