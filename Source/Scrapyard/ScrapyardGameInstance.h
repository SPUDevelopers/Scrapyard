#pragma once

#include "Engine/GameInstance.h" 

#include "Net/UnrealNetwork.h"
#include "Online.h"
#include "ScrapyardGameInstance.generated.h"

UCLASS(config=Game)
class UScrapyardGameInstance : public UGameInstance
{
public:
	GENERATED_BODY()

	UScrapyardGameInstance(const FObjectInitializer& ObjectInitializer);

	/* Function to host a game

	@Param	UserId			User that started the request
	@Param	SessionName		Name of the session
	@Param	bIsLan			Is this a LAN game?
	@Param	bIsPresence		Is this a presence session?
	@Param	MaxNumPlayers	Maximum number of players allowed on the session (Server)
	*/
	bool HostSession(TSharedPtr<const FUniqueNetId> UserId, FName SessionName, bool bIsLan, bool bIsPresence, int32 MaxNumPlayers);

	/* Function called when a session create request has completed

	@Param	SessionName		The name of the session for this callback
	@Param	bWasSuccessful	true if the async action completed without error
	*/
	virtual void OnCreateSessionComplete(FName SessionName, bool bWasSuccessful);

	/* Function called when a start session request has completed

	@Param	SessionName		The name of the session for this callback
	@Param	bWasSuccessful	true if the async action compelted without error
	*/
	void OnStartOnlineGameComplete(FName SessionName, bool bWasSuccessful);

	/* Find an online session

	@Param	UserId			User that initiated that request
	@Param	Sessionname		Name of session this search will generate
	@Param	bIsLan			Are we searching for LAN matches?
	@Param	bIsPresence		Are we searching presence sessions?
	*/
	void FindSessions(TSharedPtr<const FUniqueNetId> UserId, FName SessionName, bool bIsLan, bool bIsPresence);

	/* Delegate called on session search complete

	@Param	bWasSuccessful	True if the async action completed successfully
	*/
	void OnFindSessionsComplete(bool bWasSuccessful);

	/* Joins a session via a search result

	@Param	SessionName		Name of session
	@Param	SearchResult	Session to join

	@return bool			true if successful, false otherwise
	*/
	bool JoinSession(TSharedPtr<const FUniqueNetId> UserId, FName SessionName, const FOnlineSessionSearchResult& SearchResult);

	/*	Delegate called when a session join request has completed

	@Param SessionName		The name of the session this callback is for
	@Param bWasSuccessful	true if the async action compelted without error
	*/
	void OnJoinSessionComplete(FName SessionName, EOnJoinSessionCompleteResult::Type Result);

	/* Called after destorying an online session

	@Param	SessionName		The name of the session this callback is for
	@Param	bWasSuccessful	true if the async action completed without error
	*/
	virtual void OnDestroySessionComplete(FName Sessionname, bool bWasSuccessful);


	/////////////Online Session System Delegates/////////////
	/* Called when on session creation */
	FOnCreateSessionCompleteDelegate OnCreateSessionCompleteDelegate;
	/* Called when session is started */
	FOnStartSessionCompleteDelegate OnStartSessionCompleteDelegate;
	/* Called when searching for sessions */
	FOnFindSessionsCompleteDelegate OnFindSessionsCompleteDelegate;
	/* Called when joining a session */
	FOnJoinSessionCompleteDelegate	OnJoinSessionCompleteDelegate;
	/* Called when destroying a session */
	FOnDestroySessionCompleteDelegate OnDestroySessionCompleteDelegate;



	/* Handles to registered delegates for creating/starting a session */
	FDelegateHandle OnCreateSessionCompelteDelegateHandle;
	FDelegateHandle OnStartSessionCompleteDelegateHandle;
	/* Handle to registered delegate for searching a session */
	FDelegateHandle OnFindSessionsCompleteDelegateHandle;
	/* Handle to registered delegate for joining a session */
	FDelegateHandle OnJoinSessionCompleteDelegateHandle;
	/* Handle to registered delegate for destroying a session */
	FDelegateHandle OnDestroySessionCompleteDelegateHandle;

	// TODO: Abstract this to a class to handle this more appropiatly
	TSharedPtr<class FOnlineSessionSettings> SessionSettings;

	TSharedPtr<class FOnlineSessionSearch> SessionSearch;

	/////////////Blueprint Callable Functions/////////////
	UFUNCTION(BlueprintCallable, Category="Network|Test")
	void StartOnlineGame();

	UFUNCTION(BlueprintCallable, Category="Network|Test")
	void JoinOnlineGame();

	UFUNCTION(BlueprintCallable, Category="Network|Test")
	void DestroySessionAndLeaveGame();

	UFUNCTION(BlueprintCallable, BlueprintPure, Category="Scrapyard")
	UScrapyardGameInstance* GetGameInstance();
	//////////////////////////////////////////////////////

};