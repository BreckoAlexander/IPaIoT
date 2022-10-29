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
    - vytvoriť index.php
</ol>


### index.php
```php
    <?php echo '<p>First web on Azure</p>'; ?>
```
