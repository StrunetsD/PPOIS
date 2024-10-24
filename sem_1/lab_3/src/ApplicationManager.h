#ifndef APPLICATIONMANAGER_H
#define APPLICATIONMANAGER_H

#include "includes.h"

class ApplicationManager {
public:
    ApplicationManager() {
        manager_ = new ProjectManager("Alice", 35, 100000);
        gameProject_ = new GameProject("Epic Adventure", *manager_);
        developer_ = new Developer("Bob", 30, 80000);
        levelDesigner_ = new LevelDesigner("Charlie", 28, 70000);
        charDesigner_ = new CharacterDesigner("David", 32, 75000);
        animator_ = new Animator("Eva", 29, 68000);
        aiEngineer_ = new AIEngineer("Frank", 34, 85000);
        mechDesigner_ = new MechanicsDesigner("Grace", 31, 73000);
        tester_ = new QA("Hank", 27, 62000);
        soundDesigner_ = new SoundDesigner("Ivy", 29, 64000);
        uiuxDesigner_ = new UIUXDesigner("Jack", 26, 71000);
        artist_ = new Artist("Liam", 33, 76000);
        myBank_ = new Bank("Bank", 1000.0);
        t1_ = new Transaction("deposit", 500.0);
        t2_ = new Transaction("withdrawal", 200.0);
        gameProject_->addTeamMember(developer_);
        gameProject_->addTeamMember(levelDesigner_);
        gameProject_->addTeamMember(charDesigner_);
        gameProject_->addTeamMember(animator_);
        gameProject_->addTeamMember(aiEngineer_);
        gameProject_->addTeamMember(mechDesigner_);
        gameProject_->addTeamMember(tester_);
        gameProject_->addTeamMember(soundDesigner_);
        gameProject_->addTeamMember(uiuxDesigner_);
        gameProject_->addTeamMember(artist_);
        category_ = new Category("MOBA");
        game_ = new Game("dota 2 ", "online", category_);
    }


    void startDevelopment() const {
        gameProject_->startDevelopment();

        charDesigner_->designCharacter("Hero");
        charDesigner_->chooseAppearance();
        charDesigner_->assignWeapon("Sword");

        mechDesigner_->createCombatSystem();
        mechDesigner_->balanceGameMechanics();

        aiEngineer_->developAI();
        aiEngineer_->setAIPatrolRoutes();

        levelDesigner_->designLevel();
        levelDesigner_->placeObjects();

        animator_->animateCharacter();
        animator_->animateObjects();

        soundDesigner_->createSoundEffects();
        soundDesigner_->composeMusic();

        uiuxDesigner_->designUI();
        uiuxDesigner_->createUXFlow();

        artist_->createGameAssets();
        artist_->developConceptArt();

        tester_->testGame();

        gameProject_->releaseGame();

        cout<<"================================================"<<'\n';
        myBank_->addTransaction(*t1_);
        myBank_->addTransaction(*t2_);
        cout << "Current balance: " << myBank_->getBalance() << endl;
        myBank_->displayTransactions();
        cout<<"================================================"<<'\n';
        game_->addDeveloper(developer_);
        game_->addTester(tester_);
        game_->displayInfo();

    }
private:
    Category* category_;
    Game* game_;
    Bank* myBank_;
    Transaction* t1_;
    Transaction* t2_;
    Transaction* deposit2_{};
    ProjectManager* manager_;
    GameProject* gameProject_;
    Developer* developer_;
    LevelDesigner* levelDesigner_;
    CharacterDesigner* charDesigner_;
    Animator* animator_;
    AIEngineer* aiEngineer_;
    MechanicsDesigner* mechDesigner_;
    QA* tester_;
    SoundDesigner* soundDesigner_;
    UIUXDesigner* uiuxDesigner_;
    Artist* artist_;
};

#endif //APPLICATIONMANAGER_H
