# This file is generated automatically, do not edit. See 'ya.make.in' and use 'utils/generate-ya-make' to regenerate it.
OWNER(g:clickhouse)

LIBRARY()

ADDINCL(
    contrib/libs/libdivide
    contrib/libs/pdqsort
)

PEERDIR(
    clickhouse/src/Core
    contrib/libs/libdivide
    contrib/libs/pdqsort
)

NO_COMPILER_WARNINGS()


SRCS(
    ActionLocksManager.cpp
    ActionsDAG.cpp
    ActionsVisitor.cpp
    AggregateDescription.cpp
    Aggregator.cpp
    ApplyWithAliasVisitor.cpp
    ApplyWithGlobalVisitor.cpp
    ApplyWithSubqueryVisitor.cpp
    ArithmeticOperationsInAgrFuncOptimize.cpp
    ArrayJoinAction.cpp
    AsynchronousMetricLog.cpp
    AsynchronousMetrics.cpp
    BloomFilter.cpp
    CatBoostModel.cpp
    ClientInfo.cpp
    Cluster.cpp
    ClusterProxy/SelectStreamFactory.cpp
    ClusterProxy/executeQuery.cpp
    CollectJoinOnKeysVisitor.cpp
    ColumnAliasesVisitor.cpp
    Context.cpp
    ConvertStringsToEnumVisitor.cpp
    CrashLog.cpp
    CrossToInnerJoinVisitor.cpp
    DDLTask.cpp
    DDLWorker.cpp
    DNSCacheUpdater.cpp
    DatabaseAndTableWithAlias.cpp
    DatabaseCatalog.cpp
    DictionaryReader.cpp
    EmbeddedDictionaries.cpp
    ExecuteScalarSubqueriesVisitor.cpp
    ExpressionActions.cpp
    ExpressionActionsSettings.cpp
    ExpressionAnalyzer.cpp
    ExternalDictionariesLoader.cpp
    ExternalLoader.cpp
    ExternalLoaderDictionaryStorageConfigRepository.cpp
    ExternalLoaderTempConfigRepository.cpp
    ExternalLoaderXMLConfigRepository.cpp
    ExternalModelsLoader.cpp
    ExtractExpressionInfoVisitor.cpp
    FillingRow.cpp
    FunctionNameNormalizer.cpp
    HashJoin.cpp
    IExternalLoadable.cpp
    IInterpreter.cpp
    IInterpreterUnionOrSelectQuery.cpp
    IdentifierSemantic.cpp
    InJoinSubqueriesPreprocessor.cpp
    InternalTextLogsQueue.cpp
    InterpreterAlterQuery.cpp
    InterpreterCheckQuery.cpp
    InterpreterCreateQuery.cpp
    InterpreterCreateQuotaQuery.cpp
    InterpreterCreateRoleQuery.cpp
    InterpreterCreateRowPolicyQuery.cpp
    InterpreterCreateSettingsProfileQuery.cpp
    InterpreterCreateUserQuery.cpp
    InterpreterDescribeQuery.cpp
    InterpreterDropAccessEntityQuery.cpp
    InterpreterDropQuery.cpp
    InterpreterExistsQuery.cpp
    InterpreterExplainQuery.cpp
    InterpreterExternalDDLQuery.cpp
    InterpreterFactory.cpp
    InterpreterGrantQuery.cpp
    InterpreterInsertQuery.cpp
    InterpreterKillQueryQuery.cpp
    InterpreterOptimizeQuery.cpp
    InterpreterRenameQuery.cpp
    InterpreterSelectQuery.cpp
    InterpreterSelectWithUnionQuery.cpp
    InterpreterSetQuery.cpp
    InterpreterSetRoleQuery.cpp
    InterpreterShowAccessEntitiesQuery.cpp
    InterpreterShowAccessQuery.cpp
    InterpreterShowCreateAccessEntityQuery.cpp
    InterpreterShowCreateQuery.cpp
    InterpreterShowGrantsQuery.cpp
    InterpreterShowPrivilegesQuery.cpp
    InterpreterShowProcesslistQuery.cpp
    InterpreterShowTablesQuery.cpp
    InterpreterSystemQuery.cpp
    InterpreterUseQuery.cpp
    InterpreterWatchQuery.cpp
    InterserverCredentials.cpp
    JoinSwitcher.cpp
    JoinToSubqueryTransformVisitor.cpp
    JoinedTables.cpp
    LogicalExpressionsOptimizer.cpp
    MarkTableIdentifiersVisitor.cpp
    MergeJoin.cpp
    MetricLog.cpp
    MutationsInterpreter.cpp
    MySQL/InterpretersMySQLDDLQuery.cpp
    NormalizeSelectWithUnionQueryVisitor.cpp
    NullableUtils.cpp
    OpenTelemetrySpanLog.cpp
    OptimizeIfChains.cpp
    OptimizeIfWithConstantConditionVisitor.cpp
    OptimizeShardingKeyRewriteInVisitor.cpp
    PartLog.cpp
    PredicateExpressionsOptimizer.cpp
    PredicateRewriteVisitor.cpp
    ProcessList.cpp
    ProfileEventsExt.cpp
    QueryAliasesVisitor.cpp
    QueryLog.cpp
    QueryNormalizer.cpp
    QueryParameterVisitor.cpp
    QueryThreadLog.cpp
    RemoveInjectiveFunctionsVisitor.cpp
    RenameColumnVisitor.cpp
    ReplaceQueryParameterVisitor.cpp
    RequiredSourceColumnsData.cpp
    RequiredSourceColumnsVisitor.cpp
    RewriteAnyFunctionVisitor.cpp
    RewriteCountVariantsVisitor.cpp
    RewriteFunctionToSubcolumnVisitor.cpp
    RewriteSumIfFunctionVisitor.cpp
    RowRefs.cpp
    Set.cpp
    SetVariants.cpp
    SortedBlocksWriter.cpp
    StorageID.cpp
    SubqueryForSet.cpp
    SystemLog.cpp
    TableJoin.cpp
    TablesStatus.cpp
    TextLog.cpp
    ThreadStatusExt.cpp
    TraceLog.cpp
    TranslateQualifiedNamesVisitor.cpp
    TreeOptimizer.cpp
    TreeRewriter.cpp
    WindowDescription.cpp
    addMissingDefaults.cpp
    addTypeConversionToAST.cpp
    castColumn.cpp
    convertFieldToType.cpp
    createBlockSelector.cpp
    evaluateConstantExpression.cpp
    executeDDLQueryOnCluster.cpp
    executeQuery.cpp
    getClusterName.cpp
    getHeaderForProcessingStage.cpp
    getTableExpressions.cpp
    inplaceBlockConversions.cpp
    interpretSubquery.cpp
    join_common.cpp
    loadMetadata.cpp
    processColumnTransformers.cpp
    replaceAliasColumnsInQuery.cpp
    sortBlock.cpp

)

END()