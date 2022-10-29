# Zadanie ESP
- Microsoft Azure Portal
- GitHub a PHP
- ESP

## Microsoft Azure Portal

V prvom kroku je potrebné vytvoriť si App Services na Microsoft Azure, kde bude bežať naša web stránka.

<ol>
  <li>Prihlásiť sa do Microsoft Azure</li>
  <li>Vytvoriť <b>App Services</b></li>

    - Subscriptions - Azure for Students Starter
    - potrebné vytvoriť Resource Group
    - name - názov vášho webu
    - publish - Code
    - Runetime stack - PHP 8 / 8.1
    - Region - najbližšie k EU
    - zvoliť free verziu
  <li>Otestovať Váš web</li>

https://phpipaiot.azurewebsites.net 

    - načíta Vám vašu webovú stránku index.php

    
  <li>Vytvoť GitHub repository</li>

    - prihlásiť sa na svoj GitHub účet
    - potrebné vytvoriť si GitHub repozitár
    - new --> public/private --> add README file

  <li>Prepojiť Micsrosoft Azure s GitHub účtom</li>

    - Otvoriť App Services
    - Deployment Centers
    - Pridať GitHub účet
    - Pridať repozitár
    - Pridať branch (vo väčšine prípadov main)

  <li>Vytvoriť si svoj prvý php web</li>
    
    - prihlasiť na sa GitHub
    - stlačiť . (bodka) 
    - prepne Vás do GitHub vývojového prostredia
    - vytvoriť vlastný index.php
</ol>


### index.php
Úvodná web stránka, ktorá vypíše text "First web on Azure"
```php
    <?php echo '<p>First web on Azure</p>'; ?>
```

### getParameters.php
Načítanie dát z URL adresy. Hodnoty sa uložia do premenných, ktoré sa následne vypíšu na web.
```php
    <?php
        echo '<h1>getParameters page</h1>';
        
        $sn1 = $_GET["a"];
        $sn2 = $_GET["b"];
        
        $text = "a=" . $sn1 . " b=" . $sn2;
        $sum = $sn1 + $sn2;
        
        echo $text;
        echo "<br>";
        echo "Sum:" . $sum;
    ?>
```

### file.php
Načítanie dát z URL adresy a uloženie do súboru
```php
    <?php
        
        $sn1 = $_GET["a"];
        $sn2 = $_GET["b"];
        
        $file1 = fopen("sensors.txt","w") or die("Unable to open file!");
        $text1 = "a=" . $sn1 . " b=" . $sn2;
        
        fwrite($file1, $text1);
        fclose($file1);
        
        $file2 = fopen("actuator.txt","w") or die("Unable to open file!");
        $text2 = "Value from actuator. Save this value to actuator.txt";
        fwrite($file2, $text2);
        fclose($file2);
        
        $file3 = fopen("actuator.txt","r") or die ("Subor neexistuje");
        $text3 = fread($file3,filesize("actuator.txt"));
        echo $text3;
        fclose($file3);
    ?>
```

### ESP code
Setup Arduino IDE:

https://randomnerdtutorials.com/installing-the-esp32-board-in-arduino-ide-windows-instructions/

    http_request.ino